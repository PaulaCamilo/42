/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:26:25 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:26:32 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	size_t		p;
	char		*c;

	if (dest == NULL && src == NULL)
		return (NULL);
	c = (char *)dest;
	s = (const char *)src;
	p = 0;
	while (p < n)
	{
		c[p] = s[p];
		p++;
	}
	return (dest);
}
