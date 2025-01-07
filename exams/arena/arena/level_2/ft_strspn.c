/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:32:53 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/03 17:58:16 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t ft_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    size_t j = 0;

    while (s[i])
    {
        j = 0;
        while (accept[j])
        {
            if (accept[j] == s[i])
                break;
            j++;
        }
        if (!accept[j])
            return (i);
        i++;
    }
    return (i);
}