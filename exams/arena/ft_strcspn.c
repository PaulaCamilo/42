/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:20:35 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/22 16:26:28 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    size_t j = 0;

    while (s[i]) // while s[i] is not null
    {
        i = 0; 
        while (reject[j]) // while reject[j] is not null
        {
            if (s[i] == reject[j]) // if s[i] is equal to reject[j]
                return (i); // return i
            j++;
        }
        i++;
    }
    return (i);
}