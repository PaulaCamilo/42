/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:13:42 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/22 15:15:34 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char w)
{
	write (1, &w, 1);
}

void	ft_print_comb2(void)
{
	int	first_number;
	int	second_number;

	first_number = 0;
	while (first_number < 99)
	{
		second_number = first_number + 1;
		while (second_number <= 99)
		{
			ft_putchar(first_number / 10 + '0');
			ft_putchar(first_number % 10 + '0');
			ft_putchar(' ');
			ft_putchar(second_number / 10 + '0');
			ft_putchar(second_number % 10 + '0');
			if (first_number != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			second_number++;
		}
		first_number++;
	}
}
