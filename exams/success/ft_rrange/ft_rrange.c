/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:36:17 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/09 12:39:51 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int i = 0;
    int length = abs(end - start) + 1;
    int *array = malloc(sizeof(int) * length);
    int step;

    if (start > end)
        step = 1;
    else
        step = -1;
        
    while (i < length)
    {
            array[i] = end;
            end = end + step;
            i++;
    }
    return (array);
}