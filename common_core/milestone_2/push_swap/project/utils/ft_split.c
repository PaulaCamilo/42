/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:10:08 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/30 13:50:25 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_counter(const char *str, char c)
{
	int i;
	int inside_word;

	i = 0;
	inside_word = 0;
	while (*str)
	{
		if (*str != c && inside_word == 0)
		{
			inside_word = 1;
			i++;
		}
		else if (*str == c)
			inside_word = 0;
		str++;
	}
	return (i);
}

static char	*word_duplicate(const char *str, int start, int finish)
{
	char *word;
	int	i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int			index;
	char		**split;

	split = malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_duplicate(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}