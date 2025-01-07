/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:36:12 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/15 09:36:16 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_params(char *str)
{
	int	p;

	p = 0;
	while (str[p] != '\0')
	{
		ft_putchar(str[p]);
		p++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_print_params(av[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
