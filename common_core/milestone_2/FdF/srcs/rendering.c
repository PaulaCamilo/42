/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:04:55 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/11 16:35:22 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	project_iso(int x, int y, int z, int scale)
{
	t_point	point;
	float	angle;

	angle = 0.523598;
	point.x = (x - y) * cos(angle) * scale;
	point.y = (x + y) * sin(angle) * scale - (z * scale / 10);
	point.z = z;
	point.color = DEFAULT_COLOR;
	return (point);
}

t_point	get_projected_point_and_color(t_render *render, int i, int j)
{
	t_point	point;

	point.x = j;
	point.y = i;
	point.z = render->map[i][j].height;
	if (render->projection == 0)
		point = project_iso(point.x, point.y, point.z, render->scale);
	else if (render->projection == 1)
	{
		point = top_projection(point.x, point.y, point.z, render->scale);
	}
	point.color = get_color(point.z, render->map[i][j].has_color,
			render->map[i][j].color, render->has_any_color);
	point = rotate_point(point, render->rotation);
	point.x += render->offset_x;
	point.y += render->offset_y;
	return (point);
}

void	draw_l_next_row_point(t_render *render, t_point p1, int i, int j)
{
	t_point	p2;
	t_line	line;

	render->has_any_color = 0;
	p2 = get_projected_point_and_color(render, i, j + 1);
	line.x1 = p1.x;
	line.y1 = p1.y;
	line.x2 = p2.x;
	line.y2 = p2.y;
	line.color = p2.color;
	bresenham(render, &line);
}

void	draw_l_next_col_point(t_render *render, t_point p1, int i, int j)
{
	t_point	p3;
	t_line	line;

	render->has_any_color = 0;
	p3 = get_projected_point_and_color(render, i + 1, j);
	line.x1 = p1.x;
	line.y1 = p1.y;
	line.x2 = p3.x;
	line.y2 = p3.y;
	line.color = p3.color;
	bresenham(render, &line);
}

// Project the current point
// Draw lines to the next point in the row, if it exists
// Draw lines to the next point in the column, if it exists
void	render_map(t_render *render)
{
	t_point	p1;
	int		i;
	int		j;

	reset_image(render);
	render->has_any_color = 0;
	i = 0;
	while (i < render->rows)
	{
		j = 0;
		while (j < render->cols)
		{
			p1 = render->map[i][j];
			p1 = get_projected_point_and_color(render, i, j);
			if (j < render->cols - 1)
				draw_l_next_row_point(render, p1, i, j);
			if (i < render->rows - 1)
				draw_l_next_col_point(render, p1, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(render->mlx, render->win, render->img.img_ptr,
		0, 0);
	draw_menu(render);
}
