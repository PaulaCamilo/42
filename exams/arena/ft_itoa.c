/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:41:08 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/09 13:45:26 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int_length(long nbr)
{
    unsigned int length = 0;
    
    if (nbr < 0)
        length++;
    if (nbr == 0)
        return (1);
    while (nbr != 0)
    {
        length++;
        nbr /= 10;
    }
    return (length);    
}

char	*ft_itoa(int nbr)
{
    long n = nbr;
    long length = int_length(n);
    char *str = malloc(sizeof(char) * (length + 1));

    if (n < 0)
    {
        str[0] = '-';
        n *= -1;
    }
    if (n == 0)
        str[0] = '0';
    str[length] = '\0';
    length--;
    while (n < length)
    {
        str[length] = (n % 10) + '0';
        n /= 10;
        n++;
    }
    return (str);
}