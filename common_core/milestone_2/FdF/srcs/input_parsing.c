/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:01:10 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/17 19:46:56 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#include "../include/fdf.h"

t_point	**allocate_matrix(int rows, int max_cols)
{
	t_point	**matrix;
	int		i;
	int		j;

	matrix = ft_calloc(rows, sizeof(t_point *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = ft_calloc(max_cols, sizeof(t_point));
		if (!matrix[i])
		{
			j = 0;
			while (j < i)
			{
				free(matrix[j]);
				j++;
			}
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

static int	parse_color(char *str)
{
	char	*color_str;
	int		color;

	color_str = ft_strchr(str, ',');
	if (color_str)
	{
		color = rgb_to_int(color_str + 1);
		return (color);
	}
	return (DEFAULT_COLOR);
}

static void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	parse_line(char *line, t_point *matrix_row, int max_cols,
			t_render *render)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i] && i < max_cols)
	{
		matrix_row[i].height = ft_atoi(split[i]);
		matrix_row[i].color = parse_color(split[i]);
		matrix_row[i].has_color = render->file_has_color;
		if (matrix_row[i].has_color)
			render->has_any_color = 1;
		i++;
	}
	while (i < max_cols)
	{
		matrix_row[i].height = 0;
		matrix_row[i].color = DEFAULT_COLOR;
		matrix_row[i].has_color = 0;
		i++;
	}
	ft_free_split(split);
}

t_point	**parse_matrix(const char *filename, t_matrix *matrix_info,
			t_render *render)
{
	int		fd;
	char	*buffer;
	char	**lines;

	fd = open_file(filename);
	buffer = allocate_buffer(3 * 1024 * 1024);
	read_file(fd, buffer, 3 * 1024 * 1024);
	close(fd);
	render->file_has_color = (ft_strchr(buffer, ',') != NULL);
	lines = ft_split(buffer, '\n');
	if (!lines)
	{
		free(buffer);
		return (NULL);
	}
	matrix_info->rows = count_rows(lines);
	matrix_info->max_cols = determine_max_cols(lines, matrix_info->rows);
	matrix_info->matrix = allocate_matrix(matrix_info->rows,
			matrix_info->max_cols);
	parse_lines_matrix(lines, matrix_info->matrix, matrix_info, render);
	free(buffer);
	return (matrix_info->matrix);
}
