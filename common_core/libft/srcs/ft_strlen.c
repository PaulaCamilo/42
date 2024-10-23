/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:25:39 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:25:46 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	p;

	p = 0;
	while (s[p] != '\0')
		p++;
	return (p);
}

/*
int	main(void)
{
	char *a = "Porto";
	char *b = "42";

	printf("The length of the a string is: %d\nThe length of the b string
			is: %d\n", ft_strlen(a), ft_strlen(b));
	return (0);
}
*/
