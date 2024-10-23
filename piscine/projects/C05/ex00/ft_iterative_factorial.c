/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:13:39 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/19 09:30:16 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	while (nb > 0)
	{
		result *= nb;
		nb--;
	}
	if (nb < 0)
		return (0);
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	int	i;

	i = 5;
	printf("The factorial of %d is %d.", i, ft_iterative_factorial(i));
	return (0);
}
*/
