/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:39:37 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/05 15:26:12 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// helper function to open the file
int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening file\n");
	return (fd);
}

// helper function to allocate buffer
char	*allocate_buffer(size_t size)
{
	char	*buffer;

	buffer = ft_calloc(size, sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

// helper function to read the file into the buffer
// add null terminator
void	read_file(int fd, char *buffer, size_t size)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, size - 1);
	if (bytes_read < 0)
	{
		free(buffer);
		close(fd);
		ft_error("Failed to read matrix\n");
	}
	buffer[bytes_read] = '\0';
}
