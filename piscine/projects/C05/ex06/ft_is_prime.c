/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:11:14 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/19 10:17:55 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (nb / 2))
	{
		if (!(nb % i))
			return (0);
		else
			i += 1;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n;
	
	n = 15;
	printf("0 = not prime number | 1 = prime number\n");
	printf("Is %d a prime number? %d\n", n, ft_is_prime(n));
	return (0);
}
*/
