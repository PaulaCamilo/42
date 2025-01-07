/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:58:36 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/05 17:05:06 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i = 0;
    int length = 0;
    char *new_str;

    while (src[length])
        length++;
    new_str = malloc(sizeof(*new_str) + (length + 1));
    if (new_str != NULL)
    {
        while (src[i])
        {
            new_str[i] = src[i];
            i++;
        }
        new_str[i] = '\0';
    }
    return (new_str);
}