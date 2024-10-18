/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:17:48 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/16 13:12:45 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	p;
	unsigned int	c;

	p = 0;
	c = 0;
	while (dest[p] != '\0')
	{
		p++;
	}
	while (c < nb && src[c] != '\0')
	{
		dest[p + c] = src[c];
		c++;
	}
	dest[p + c] = '\0';
	return (dest);
}
