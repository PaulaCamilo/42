/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:25:54 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:26:01 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memset(void *str, int p, size_t n)
{
	unsigned char		*s;
	size_t				c;

	s = (unsigned char *)str;
	c = 0;
	while (c < n)
	{
		s[c] = (unsigned char)p;
		c++;
	}
	return (s);
}

/*
void	test_ft_memset(void)
{
	char buffer[50];

	//basic funcionality
	ft_memset(buffer, 'A', 5);
	buffer[5] = '\0';
	printf("Test 1: %s\n", buffer);

	//zero bytes
	ft_memset(buffer, 'C', 0);
	printf("Test 2: %s\n", buffer);

	//one byte
	ft_memset(buffer, 'C', 1);
	printf("Test 3: %s\n", buffer);

	//non-printable
	ft_memset(buffer, '\t', 5);
	printf("Test 4: %s\n", buffer);
}

int	main(void)
{
	test_ft_memset();
	return (0);
}
*/
