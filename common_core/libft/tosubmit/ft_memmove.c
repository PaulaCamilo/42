/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:26:39 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:26:45 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (s < d)
		while (n--)
			d[n] = s[n];
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}

#include <stdio.h>

void	test_memmove_overlap(void)
{
	char	str[] = "Hello, World!";
	printf("Original string: %s\n", str);
	ft_memmove((str + 7), str, 5);
	printf("After ft_memmove with overlap: %s\n", str);
}

int	main(void)
{
	test_memmove_overlap();
	return (0);
}
