/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:13:59 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/09 14:18:02 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *s)
{
    int i = 0;
    while (*s)
    {
        i = i * 10 + (*s - 48);
        s++;
    }
    return (i);
}

int is_prime(int n)
{
    int i = 2;

    if (n <= 1)
        return (0);
    while (i * i <= n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

void print_nmb(int n)
{
    if (n > 9)
        print_nmb(n / 10);
    char digit = n % 10 + '0';
    write (1, &digit, 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int nmb = ft_atoi(av[1]);
        int sum = 0;

        while (nmb > 0)
        {
            if (is_prime(nmb))
                sum += nmb;
            nmb--;
        }
        print_nmb(sum);
    }

    if (ac != 2)
        print_nmb(0);
    write (1, "\n", 1);
    return (0);
}