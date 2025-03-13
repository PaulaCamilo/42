/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:50:54 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/06 13:31:45 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	t_render	render;
	t_matrix	matrix_info;

	if (input_check(ac, av) != 0)
		return (1);
	matrix_info.matrix = parse_matrix(av[1], &matrix_info, &render);
	if (!matrix_info.matrix)
		return (1);
	if (init_render(&render, matrix_info.matrix, matrix_info.rows,
			matrix_info.max_cols) != 0)
	{
		free(render.mlx);
		free_matrix(matrix_info.matrix, matrix_info.rows);
		return (1);
	}
	render_map(&render);
	setup_and_run_mlx(&render);
	free(render.mlx);
	free_matrix(matrix_info.matrix, matrix_info.rows);
	return (0);
}
