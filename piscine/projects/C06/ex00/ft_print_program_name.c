/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:40:43 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/19 15:06:49 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char *str)
{
	int	w;

	w = 0;
	while (str[w] != '\0')
	{
		write (1, &str[w], 1);
		w++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		putchar(argv[0]);
		write (1, "\n", 1);
	}
	return (0);
}
