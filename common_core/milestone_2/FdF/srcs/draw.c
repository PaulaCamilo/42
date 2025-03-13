/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:03:17 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/05 15:44:39 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel(t_render *render, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = render->img.address
			+ (y * render->img.line_len + x * (render->img.bpp / 8));
		*(int *)pixel = color;
	}
}

static void	update_coord(t_bresenham *params)
{
	int	e2;

	e2 = 2 * *params->err;
	if (e2 > -params->dy)
	{
		*params->err -= params->dy;
		*params->x1 += params->sx;
	}
	if (e2 < params->dx)
	{
		*params->err += params->dx;
		*params->y1 += params->sy;
	}
}

static void	set_step(t_bresenham *params)
{
	if (*params->x1 < params->x2)
		params->sx = 1;
	else
		params->sx = -1;
	if (*params->y1 < params->y2)
		params->sy = 1;
	else
		params->sy = -1;
}

void	bresenham(t_render *render, t_line *line)
{
	t_bresenham	params;
	int			err;

	params.x1 = &(line->x1);
	params.y1 = &(line->y1);
	params.x2 = line->x2;
	params.y2 = line->y2;
	params.dx = ft_abs(line->x2 - line->x1);
	params.dy = ft_abs(line->y2 - line->y1);
	err = params.dx - params.dy;
	params.err = &err;
	set_step(&params);
	while (1)
	{
		put_pixel(render, line->x1 + (WIDTH / 2),
			line->y1 + (HEIGHT / 8), line->color);
		if (line->x1 == line->x2 && line->y1 == line->y2)
			break ;
		update_coord(&params);
	}
}
