/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:03:03 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/19 10:10:30 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	index;
	long	counter;

	counter = nb;
	if (counter <= 0)
		return (0);
	if (counter == 1)
		return (1);
	index = 2;
	if (counter >= 2)
	{
		while (index * index <= counter)
		{
			if (index * index == counter)
				return (index);
			index++;
		}
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int	n;

	n = 16;
	printf("The square root of %d is %d.\n", n, ft_sqrt(n));
	return (0);
}
*/
