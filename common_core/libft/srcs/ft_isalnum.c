/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:24:38 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:24:50 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isalnum(int p)
{
	if ((ft_isalpha(p) == 1) || (ft_isdigit(p) == 1))
		return (1);
	return (0);
}

/*
int	main(void)
{
	char a = ' ';
	char b = '\t';
	char c = 'P';
	char d = '8';

	printf("The value of a, b, c, d is: %d, %d, %d, %d\n", ft_isalnum(a),
			ft_isalnum(b), ft_isalnum(c), ft_isalnum(d));
	return (0);
}
*/
