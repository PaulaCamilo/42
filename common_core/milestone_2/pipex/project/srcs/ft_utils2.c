/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:30:56 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/10 10:13:36 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	p;
	size_t	c;

	p = 0;
	c = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (big[p] && p < n)
	{
		while (big[p + c] == little[c] && big[p + c] && p + c < n)
		{
			c++;
			if (little[c] == '\0')
				return ((char *) big + p);
		}
		p++;
		c = 0;
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	size_t			p;
	const char		*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	p = 0;
	while (p < n)
	{
		d[p] = s[p];
		p++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, len_s1);
	ft_memcpy((res + len_s1), s2, len_s2);
	res[len_s1 + len_s2] = '\0';
	return (res);
}
