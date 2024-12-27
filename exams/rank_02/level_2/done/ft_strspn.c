/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:20:05 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/13 09:22:41 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	int j = 0;
	
	while (s[i] != '\0')
	{
		while (accept[j] != '\0')
		{
			if (accept[j] == s[i])
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}