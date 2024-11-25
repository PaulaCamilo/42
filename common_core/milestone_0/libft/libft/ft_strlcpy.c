/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:26:55 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:27:03 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	p;

	if (size > 0)
	{
		p = 0;
		while (p < (size - 1) && src[p] != '\0')
		{
			dest[p] = src[p];
			p++;
		}
		dest[p] = '\0';
	}
	return (ft_strlen(src));
}
