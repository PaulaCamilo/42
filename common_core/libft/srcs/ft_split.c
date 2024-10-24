/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:41:07 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/24 08:41:10 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_tokens(char const *s, char delimeter);
static int		safe_malloc(char **token_v, int pos, size_t buffer);
static int		fill_array(char **token_v, char const *s, char delimeter);

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**token_v;

	if (NULL == s)
		return (NULL);
	tokens = 0;
	tokens = count_tokens(s, c);
	token_v = malloc((tokens + 1) * sizeof(char *));
	if (NULL == token_v)
		return (NULL);
	if (fill_array(token_v, s, c))
		return (NULL);
	token_v[tokens] = NULL;
	return (token_v);
}

static size_t	count_tokens(char const *s, char delimeter)
{
	size_t	tokens;

	tokens = 0;
	while (*s)
	{
		while (*s == delimeter && *s)
			++s;
		if (*s)
			++tokens;
		while (*s != delimeter && *s)
			++s;
	}
	return (tokens);
}

static int	safe_malloc(char **token_v, int pos, size_t buffer)
{
	int	i;

	i = 0;
	token_v[pos] = malloc(buffer);
	if (token_v[pos] == NULL)
	{
		while (i < pos)
			free(token_v[i++]);
		free (token_v);
		return (1);
	}
	return (0);
}

static int	fill_array(char **token_v, char const *s, char delimeter)
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
			if (safe_malloc(token_v, i, len + 1))
				return (1);
			ft_strlcpy(token_v[i], s - len, len + 1);
			++i;
		}
	}
	return (0);
}
