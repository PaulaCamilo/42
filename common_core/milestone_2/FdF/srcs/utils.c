/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:17:11 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/11 16:32:42 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	rgb_to_int(char *color)
{
	int	r;
	int	g;
	int	b;
	int	color_value;

	if (color[0] == '0' && (color[1] == 'x' || color[1] == 'X'))
		color += 2;
	color_value = ft_atoi_base(color, 16);
	r = color_value / (256 * 256);
	color_value = color_value % (256 * 256);
	g = color_value / 256;
	b = color_value % 256;
	return ((r * 256 * 256) + (g * 256) + b);
}

void	free_matrix(t_point **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

// Store original y and z values
// Rotate around the Y-axis
// point.x remains unchanged
// Return the modified point
t_point	rotate_point(t_point point, double rotation_x)
{
	double	radian_x;
	double	temp_y;
	double	temp_z;

	radian_x = rotation_x * PI / 180.0;
	temp_y = point.y;
	temp_z = point.z;
	point.y = temp_y * cos(radian_x) - temp_z * sin(radian_x);
	point.z = temp_y * sin(radian_x) + temp_z * cos(radian_x);
	return (point);
}

t_point	top_projection(int x, int y, int z, int scale)
{
	t_point	point;

	point.x = x * scale;
	point.y = y * scale;
	point.z = z;
	return (point);
}
