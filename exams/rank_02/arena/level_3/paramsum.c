/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:28:58 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/19 11:30:21 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void put_nbr(int n)
{
	if (n >= 10)
		put_nbr(n / 10);
	char digit = n % 10 + '0';
	write (1, &digit, 1);
}

int main (int ac, char **av)
{
	(void)av;
	if (ac > 1)
		put_nbr(ac - 1);
	write (1, "\n", 1);
	return (0);
}