/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:31:02 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/28 14:38:12 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int a = atoi(av[1]);
        int b = atoi(av[2]);
        int n = 0;

        n = a;
        while (n > 0)
        {
            if (a % n == 0 && b % n == 0)
            {
                printf("%d", n);
                break ;
            }
            n--;
        }
    }
    printf("\n");
    return (0);
}