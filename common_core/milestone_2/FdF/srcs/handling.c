/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:15:55 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/11 16:27:39 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_keypress(int keycode, t_render *render)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(render->mlx, render->img.img_ptr);
		mlx_destroy_window(render->mlx, render->win);
		mlx_destroy_display(render->mlx);
		free(render->mlx);
		free_matrix(render->map, render->rows);
		exit(0);
	}
	handle_zoom_rotate(keycode, render);
	handle_move_proj(keycode, render);
	render_map(render);
	return (0);
}

void	handle_zoom_rotate(int keycode, t_render *render)
{
	if (keycode == ZOOM_IN)
		render->scale += 5;
	if (keycode == ZOOM_OUT && render->scale > 1)
		render->scale -= 5;
	if (keycode == ROTATE)
		render->rotation += 1;
	if (keycode == RESET_VIEW)
		render->rotation = 0;
	if (keycode == RESET_ZOOM)
		render->scale = SCALE;
}

void	handle_move_proj(int keycode, t_render *render)
{
	if (keycode == ARROW_UP)
		render->offset_y -= 10;
	if (keycode == ARROW_DOWN)
		render->offset_y += 10;
	if (keycode == ARROW_LEFT)
		render->offset_x -= 10;
	if (keycode == ARROW_RIGHT)
		render->offset_x += 10;
	if (keycode == ISO_VIEW)
	{
		render->rotation = 0;
		render->projection = 0;
	}
	if (keycode == TOP_VIEW)
	{
		render->rotation = 0;
		render->projection = 1;
	}
}

int	handle_close(t_render *render)
{
	mlx_destroy_image(render->mlx, render->img.img_ptr);
	mlx_destroy_window(render->mlx, render->win);
	mlx_destroy_display(render->mlx);
	free(render->mlx);
	free_matrix(render->map, render->rows);
	exit(0);
	return (0);
}
