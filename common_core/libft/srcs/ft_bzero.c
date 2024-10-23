/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:26:08 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:26:16 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>
//#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = '\0';
}

/*
void	test_nullpointer_ft_bzero(void)
{
	char* null_ptr = NULL;
	ft_bzero(null_ptr, 10);
}

void	test_nullpointer_bzero(void)
{
	char* null_ptr = NULL;
	bzero(null_ptr, 10);
}


void	test_zero_length_ft_bzero(void)
{
	char buffer[10];
	ft_bzero(buffer, 0);
	printf("Buffer after zero-length ft_bzero: %s\n", buffer);
}

void	test_zero_length_bzero(void)
{
	char buffer[10];
	//bzero(buffer, 0);
	printf("Buffer after zero-length bzero: %s\n", buffer);
}

int	main(void)
{
	//test_nullpointer_ft_bzero();
	//test_nullpointer_bzero();
	test_zero_length_ft_bzero();
	//test_zero_length_bzero();
	return (0);
}
*/
