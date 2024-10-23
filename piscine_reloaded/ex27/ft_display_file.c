/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:37:10 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/16 16:37:12 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char w)
{
	write(1, &w, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_display(char *string)
{
	char	p;
	int		file_ptr;

	file_ptr = open(string, O_RDONLY, 0);
	if (file_ptr == -1)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	while (read(file_ptr, &p, 1) == 1)
		ft_putchar(p);
	close(file_ptr);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	if (ac == 2)
		ft_display(av[1]);
	if (ac > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	return (0);
}
