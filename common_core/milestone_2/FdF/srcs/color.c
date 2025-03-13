/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:08:46 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/11 15:23:43 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_color(int z, int has_color, int color, int has_any_color)
{
	if (has_color)
		return (color);
	else
	{
		if (!has_any_color)
		{
			if ((z > -100) && (z <= -50))
				return (0x0F1644);
			else if ((z > -50) && (z < 0))
				return (0xB56422);
			else if (z == 0)
				return (0x096191);
			else if (z > 0 && z < 50)
				return (0x3D838B);
			else
				return (0xEBD8AE);
		}
		else
			return (DEFAULT_COLOR);
	}
	return (0);
}
