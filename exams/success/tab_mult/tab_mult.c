/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:16:09 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/14 12:35:28 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *s)
{
    int i = 0;
    int res = 0;

    while (s[i])
    {
        res = res * 10 + (s[i] - 48);
        i++;
    }
    return (res);
}

void put_nbr(int n)
{
    if (n > 9)
        put_nbr(n / 10);
    char digit = n % 10 + '0';
    write (1, &digit, 1);
}

int main(int ac, char **av)
{
    int i;
    int mult;
    
    if (ac != 2)
        write (1, "\n", 1);
    else
    {
        i = 1;
        mult = ft_atoi(av[1]);
        while (i <= 9)
        {
            put_nbr(i);
            write (1, " x ", 3);
            put_nbr(mult);
            write (1, " = ", 3);
            put_nbr (i * mult);
            write (1, "\n", 1);
            i++;
        }
    }
    return (0);
}