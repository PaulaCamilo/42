/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:31:50 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/19 09:39:07 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	while (power > 1)
	{
		result *= nb;
		power--;
	}
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	int	n;
	int	p;

	n = 2;
	p = 5;
	printf("%d power %d is %d.\n", n, p, ft_iterative_power(n, p));
	return (0);
}
*/
