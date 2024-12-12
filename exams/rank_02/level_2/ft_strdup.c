/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:58:17 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/12 14:12:45 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	int length = 0;
	char *strcpy;

	while (src[length])
		length++;
	strcpy = malloc(sizeof(*strcpy) * (length + 1));
	if (strcpy != NULL)
	{
		while (src[i])
		{
			strcpy[i] = src[i];
			i++;
		}
		strcpy = '\0';
	}
	return (strcpy);
}

#include <stdio.h>

int main(void)
{
	char *str = "Zedro 42";
	char *dup;

	dup = ft_strdup(str);
	printf("      str : %s\n", str);
	printf("ft_strdup : %s\n", dup);

	return (0);
}