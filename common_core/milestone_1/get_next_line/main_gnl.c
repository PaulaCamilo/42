/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:56:00 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/25 13:01:03 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("tests/simple", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL);
			return (NULL);
		printf("%s", line);
		free(line);
	}
	return (0);
}