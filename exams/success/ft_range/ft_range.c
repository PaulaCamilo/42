/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:07:52 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/08 20:11:37 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int i = 0;
    int length = abs(end - start) + 1;
    int *new = malloc(sizeof(int) * length);
    
    while (i < length)
    {
        if (start < end)
        {
            new[i] = start;
            start++;
            i++;
        }
        else
        {
            new[i] = start;
            start--;
            i++;
        }
    }
    return (new);
}