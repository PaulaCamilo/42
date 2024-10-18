/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:23:02 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:23:04 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

int	ft_isdigit(int p)
{
	if (p >= '0' && p <= '9')
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	a = '8';
	int b = 'P';

	printf("The value of a is: %d\nThe value of b is: %d\n",
			ft_isdigit(a), ft_isdigit(b));
	return (0);
}
*/
