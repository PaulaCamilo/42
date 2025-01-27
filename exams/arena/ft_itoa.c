/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:41:08 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/22 16:34:57 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int_length(long nbr) 
{
    unsigned int length = 0; // length is unsigned int because it will never be negative
    if (nbr < 0)
        length++; // increment length if nbr is negative
    if (nbr == 0)
        return (1);
    while (nbr != 0) // while nbr is not 0
    {
        length++; // increment length
        nbr /= 10; // divide nbr by 10 to get the next digit
    }
    return (length);
}

char *ft_itoa(int nbr)
{
    long n = nbr; // convert int to long
    long length = int_length(n); // get the length of the number
    char *str = malloc(sizeof(char) * length + 1); // allocate memory for the string

    if (n < 0)
    {
        str[0] = '-';
        n *= -1;
    }
    if (n == 0)
        str[0] = '0';
    while (n != 0) // while n is not 0
    {
        str[length] = (n % 10) + '0'; // get the last digit of n and convert it to char
        n /= 10; // divide n by 10 to get the next digit
        length--; // decrement length
    }
    return (str); // return the string
}