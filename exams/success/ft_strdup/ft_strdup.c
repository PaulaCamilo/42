/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:17:28 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/08 16:26:16 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i = 0;
    char *new;

    while (src[i])
        i++;
    new = malloc(sizeof(*new) * (i + 1));
    if (new == NULL)
        return (NULL);
    i = 0;
    while (src[i])
        {
            new[i] = src[i];
            i++;
        }
    new[i] = src[i];
    return (new);
}