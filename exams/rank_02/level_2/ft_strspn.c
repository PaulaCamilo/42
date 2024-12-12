/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:47:49 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/12 14:51:55 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	size_t j = 0;

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

#include <stdio.h>

int main(void)
{
	char	*s = "Zedro 420";
	char	*accept = "Zedro";
	size_t	bytes = 0;

	bytes = ft_strspn(s, accept);
	printf("%zu\n", bytes);

	return (0);
}