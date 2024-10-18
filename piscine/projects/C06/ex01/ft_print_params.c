/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:47:58 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/19 15:11:21 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char w)
{
	write (1, &w, 1);
}

int	main(int argc, char **argv)
{
	int	p;
	int	c;

	p = 1;
	while (p < argc)
	{
		c = 0;
		while (argv[p][c] != '\0')
		{
			putchar(argv[p][c]);
			c++;
		}
		putchar ('\n');
		p++;
	}
	return (0);
}
