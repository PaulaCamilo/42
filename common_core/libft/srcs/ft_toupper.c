/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:27:32 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:27:39 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_toupper(int p)
{
	if ('a' <= p && p <= 'z')
		return (p - 32);
	return (p);
}

/*
int	main(void)
{
	int	p = 98;

	printf("The uppercase of %c is: %c\n", p, ft_toupper(p));
	return (0);
}
*/
