/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:57:01 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/21 19:02:04 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int i = 0; // counter
    int length = abs(end - start) + 1; // length of the given array
    int *array = malloc(sizeof(int) * length); // allocate memory for the array
    int step; // step to increment or decrement the value

    // if the start is greater than the end, it means we need to decrement 
    // the value, otherwise we need to increment the value
    if (start > end) 
        step = 1;
    else
        step = -1;
    while (i < length) // while the counter is less than the length
    {
        array[i] = end; // set the value of the array to the end
        end = end + step; // increment or decrement the end value
        i++;
    }
    return (array); // return the array with the values
}