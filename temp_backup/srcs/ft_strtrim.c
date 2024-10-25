/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:56:46 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/23 13:56:47 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const c, char const *str)
{
	size_t	p;

	p = 0;
	while (str[p])
	{
		if (str[p] == c)
			return (1);
		p++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	while (s1[start] && in_set(s1[start], set))
		start++;
	while (end > start && in_set(s1[end], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
