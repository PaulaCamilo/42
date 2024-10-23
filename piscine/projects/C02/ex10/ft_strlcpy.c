/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:20:04 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/23 10:20:13 by ppaula-d         ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	p;

	if (size == 0)
		return (ft_strlen(src));
	p = 0;
	while (src[p] != '\0' && p < size - 1)
	{
		dest[p] = src[p];
		p++;
	}
	dest[p] = '\0';
	return (ft_strlen(src));
}
