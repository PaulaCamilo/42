/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:01:11 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/08 20:05:25 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void write_nbr(int nbr)
{
    if (nbr > 9)
        write_nbr(nbr / 10);
    char digit = nbr % 10 + '0';
    write (1, &digit, 1);
}

int main(int ac, char **av)
{
    int i = 1;

    while (i <= 100)
    {
        if (i % 5 == 0 && i % 3 == 0)
            write (1, "fizzbuzz", 8);
        else if (i % 5 == 0)
            write (1, "buzz", 4);
        else if (i % 3 == 0)
            write (1, "fizz", 4);
        else
            write_nbr(i);
        write (1, "\n", 1);
        i++;
    }
    return (0);
}