/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:34:45 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/30 08:37:04 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_number(int n)
{
    if (n > 9)
        print_number(n / 10);
    char digit = n % 10 + '0';
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
            print_number(i);
        i++;
        write (1, "\n", 1);
    }
    return (0);
}