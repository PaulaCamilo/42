/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:41:32 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/19 09:47:07 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power > 1)
		return (nb * ft_recursive_power(nb, (power - 1)));
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
	printf("%d power %d is %d.\n", n, p, ft_recursive_power(n, p));
	return (0);
}
*/
