/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:26:12 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/21 18:28:21 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str) // atoi function, converts a string to an integer
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (str[i])
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result);
}

void	print_hex(int n) // function that prints a number in hexadecimal
{
    char hex[17] = "0123456789abcdef";

    if (n >= 16)
        print_hex(n / 16);
    write(1, &hex[n % 16], 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
        print_hex(ft_atoi(av[1]));
    write(1, "\n", 1);
    return (0);
}