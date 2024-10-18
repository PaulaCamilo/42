/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:22:21 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:22:23 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isalpha(int p)
{
	if ((p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z'))
		return (1);
	return (0);
}

/*
int	main(void)
{
	char a = 'P';
	char b = '3';

	printf("The value of a is: %d\nThe value of b is: %d\n",
			ft_isalpha(a), ft_isalpha(b));
	return(0);
}
*/
