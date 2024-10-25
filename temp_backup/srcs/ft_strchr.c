/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:28:14 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:28:20 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	p;
	char			cc;

	cc = (char) c;
	p = 0;
	while (s[p])
	{
		if (s[p] == cc)
			return ((char *) &s[p]);
		p++;
	}
	if (s[p] == cc)
		return ((char *) &s[p]);
	return (NULL);
}
