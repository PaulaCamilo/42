/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:28:47 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:28:54 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	p;

	p = 0;
	if (n == 0)
		return (0);
	while ((s1[p] == s2[p]) && (p < n - 1) && s1[p] != '\0' && s2[p] != '\0')
		p++;
	return ((unsigned char)s1[p] - (unsigned char)s2[p]);
}
