/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:56:00 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/27 11:02:52 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("BUFFER->%s", line);
		if (line == NULL)
			break ;
		free (line);
	}
	return (0);
}

// cc -Wall -Wextra -Werror get_next_line/* -D BUFFER_SIZE=10 -o get_next_line

// cc -Wall -Wextra -Werror get_next_line/* -D BUFFER_SIZE=10 -o get_next_line && ./get_next_line

// cc -Wall -Wextra -Werror get_next_line/* -D BUFFER_SIZE=10 -o get_next_line && ./get_next_line | cat -e