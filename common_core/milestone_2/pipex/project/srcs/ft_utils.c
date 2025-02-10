/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:28 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/10 10:16:10 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

static int	safe_malloc(char **array, int pos, size_t buffer)
{
	int	i;

	i = 0;
	array[pos] = malloc(buffer);
	if (array[pos] == NULL)
	{
		while (i < pos)
			free(array[i++]);
		free (array);
		return (1);
	}
	return (0);
}

static int	fill_array(char **array, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (safe_malloc(array, i, len + 1))
				return (1);
			ft_strlcpy(array[i], s - len, len + 1);
			++i;
		}
	}
	return (0);
}

static size_t	count_words(char const *s, char delimeter)
{
	size_t	num_words;

	num_words = 0;
	while (*s)
	{
		while (*s == delimeter && *s)
			++s;
		if (*s)
			++num_words;
		while (*s != delimeter && *s)
			++s;
	}
	return (num_words);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	char	**array;

	if (!s)
		return (NULL);
	num_words = 0;
	num_words = count_words(s, c);
	array = malloc(sizeof(char *) * (num_words + 1));
	if (!array)
		return (NULL);
	array[num_words] = 0;
	if (fill_array(array, s, c))
		return (NULL);
	array[num_words] = NULL;
	return (array);
}
