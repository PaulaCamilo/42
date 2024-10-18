/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:25:05 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/25 08:25:13 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	p;

	p = 0;
	while (str[p] != '\0')
		p++;
	return (p);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	p;
	unsigned int	c;
	unsigned int	dlen;
	unsigned int	slen;

	p = 0;
	c = 0;
	while (dest[c] != '\0')
		c++;
	dlen = c;
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[p] != '\0' && p < size - dlen - 1)
	{
		dest[c] = src[p];
		p++;
		c++;
	}
	dest[c] = '\0';
	return (dlen + slen);
}
