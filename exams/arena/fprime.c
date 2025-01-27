/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:07:16 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/22 16:14:24 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int i; // i is the factor
    int number; // number to find the factors of

    if (ac == 2)
    {
        i = 1; // i = 1 because we want to start from 2
        number = atoi(av[1]); // convert string to integer
        if (number == 1)
            printf("1");
        while (number >= ++i) // increment i before comparison
        {
            if (number % i == 0) // if number is divisible by i
            {
                printf("%d", i);
                if (number == i) // if number is equal to i, this is the last factor
                    break;
                printf("*"); // print * if there are more factors
                number /= i; // divide number by i to get the next factor
                i = 1; // reset i to 1 to start from 2 again
            }
        }
    }
    printf("\n");
    return (0);
}