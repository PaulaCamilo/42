/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_helpers2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:41:07 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/05 15:13:03 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	count_rows(char **lines)
{
	int	rows;

	rows = 0;
	while (lines[rows])
		rows++;
	return (rows);
}

int	count_columns(char *line)
{
	int	count;
	int	in_number;

	count = 0;
	in_number = 0;
	while (*line)
	{
		if (*line != ' ' && !in_number)
		{
			in_number = 1;
			count++;
		}
		else if (*line == ' ')
			in_number = 0;
		line++;
	}
	return (count);
}

int	determine_max_cols(char **lines, int rows)
{
	int	max_cols;
	int	cols;
	int	i;

	max_cols = 0;
	i = 0;
	while (i < rows)
	{
		cols = count_columns(lines[i]);
		if (cols > max_cols)
			max_cols = cols;
		i++;
	}
	return (max_cols);
}

void	parse_lines_matrix(char **lines, t_point **matrix,
			t_matrix *matrix_info, t_render *render)
{
	int	i;

	(void)matrix;
	i = 0;
	while (i < matrix_info->rows)
	{
		parse_line(lines[i], matrix_info->matrix[i], matrix_info->max_cols,
			render);
		free(lines[i]);
		i++;
	}
	free(lines);
}
