/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:24:31 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/19 14:45:15 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] && str[i] >= 33)
		i++;
	return(i);
}

int word_count(char *str)
{
	int i = 0;
	int words = 0;
	
	while (str[i])
	{
		if (str[i] >= 33 && str[i - 1] <= 33)
			words++;
		i++;
	}
	return (words);
}

int check_spaces(char *str)
{
	int i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	return (i);
}

char **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wordsint = word_count(str);
	char **str_split = (char **)malloc(sizeof(char *) * (word_count(str) + 1));

	
}