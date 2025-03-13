/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:34:34 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/05 15:27:48 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// check the correct number of arguments
int	check_ac(int ac)
{
	if (ac < 2 || ac > 2)
	{
		ft_putstr_fd("Invalid input. Try: ./fdf map_name.fdf\n", 2);
		return (1);
	}
	return (0);
}

// check the correct extension of the file
// check min for filename
int	check_av(char *av)
{
	if (ft_strcmp(av + ft_strlen(av) - 4, ".fdf") != 0)
	{
		ft_putstr_fd("Error: file must have a .fdf extension\n", 2);
		return (1);
	}
	if (ft_strlen(av) < 5)
	{
		ft_putstr_fd("Error: invalid file name\n", 2);
		return (1);
	}
	return (0);
}

// try to open the file
// check if the file is a directory
// check if the file is empty by attempting to read the first byte
// therefore the need for the buffer of one byte
// even after successful read, you need to close the file
int	check_file(char *av)
{
	int		fd;
	int		dir_fd;
	char	buffer[1];

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_error("Error: cannot open file\n");
		return (1);
	}
	dir_fd = open(av, O_RDONLY | __O_DIRECTORY);
	if (dir_fd != -1)
	{
		ft_error("Error: file is a directory\n");
		return (close(dir_fd), close(fd), 1);
	}
	if (read(fd, buffer, 1) == 0)
	{
		ft_error("Error: file is empty\n");
		return (close(fd), 1);
	}
	return (close(fd), 0);
}

int	input_check(int ac, char **av)
{
	check_ac(ac);
	check_file(av[1]);
	check_av(av[1]);
	return (0);
}
