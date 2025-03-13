/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:15:55 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/11 16:27:39 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	init_render(t_render *render, t_point **data_array, int rows, int max_cols)
{
	render->mlx = mlx_init();
	if (!render->mlx)
		return (1);
	render->win = mlx_new_window(render->mlx, WIDTH, HEIGHT, "FdF");
	if (!render->win)
	{
		free(render->mlx);
		return (1);
	}
	render->img.img_ptr = mlx_new_image(render->mlx, WIDTH, HEIGHT);
	if (!render->img.img_ptr)
	{
		mlx_destroy_window(render->mlx, render->win);
		free(render->mlx);
		return (1);
	}
	mlx_put_image_to_window(render->mlx, render->win,
		render->img.img_ptr, 0, 0);
	initialize_render(render, data_array, rows, max_cols);
	return (0);
}

void	initialize_render(t_render *render, t_point **data_array, int rows,
	int max_cols)
{
	render->img.address = mlx_get_data_addr(render->img.img_ptr,
			&render->img.bpp, &render->img.line_len, &render->img.endian);
	render->map = data_array;
	render->rows = rows;
	render->cols = max_cols;
	render->scale = SCALE;
	render->projection = 0;
	render->rotation = 0;
	render->offset_x = 0;
	render->offset_y = 0;
	render->has_any_color = 0;
}

void	setup_and_run_mlx(t_render *render)
{
	mlx_put_image_to_window(render->mlx, render->win,
		render->img.img_ptr, 0, 0);
	draw_menu(render);
	mlx_hook(render->win, 2, 1L << 0, handle_keypress, render);
	mlx_hook(render->win, 17, 0, handle_close, render);
	mlx_loop(render->mlx);
	mlx_destroy_image(render->mlx, render->img.img_ptr);
	mlx_destroy_window(render->mlx, render->win);
	mlx_destroy_display(render->mlx);
}

void	reset_image(t_render *render)
{
	mlx_clear_window(render->mlx, render->win);
	mlx_destroy_image(render->mlx, render->img.img_ptr);
	render->img.img_ptr = mlx_new_image(render->mlx, WIDTH, HEIGHT);
	render->img.address = mlx_get_data_addr(render->img.img_ptr,
			&render->img.bpp, &render->img.line_len, &render->img.endian);
}

void	draw_menu(t_render *render)
{
	int	y;
	int	color;

	y = 10;
	color = 0xFFFFFF;
	mlx_string_put(render->mlx, render->win, 20, y += 20, color,
		"Isometric View: 1");
	mlx_string_put(render->mlx, render->win, 20, y += 20, color,
		"Top View: 2");
	mlx_string_put(render->mlx, render->win, 20, y += 20, color,
		"Move: Arrows");
	mlx_string_put(render->mlx, render->win, 20, y += 20, color,
		"Hypno Rotation: R");
	mlx_string_put(render->mlx, render->win, 20, y += 20, color,
		"Reset Rotation: Z");
	mlx_string_put(render->mlx, render->win, 20, y += 20, color,
		"Zoom In: +");
	mlx_string_put(render->mlx, render->win, 20, y += 20, color,
		"Zoom Out: -");
	mlx_string_put(render->mlx, render->win, 20, y += 20, color,
		"Reset Zoom: Backspace");
}
