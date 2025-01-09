/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:19:21 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/09 13:26:31 by ppaula-d         ###   ########.fr       */
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
    char *new = malloc(sizeof(char) * (length + 1));

    if (nbr < 0)
    {
        new[0] = '-';
        nbr *= -1;
    }
    if (nbr == 0)
        new[0] = '0';
    new[length] = '\0';
    length--;
    while (nbr != 0)
    {
        new[length] = (nbr % 10) + '0';
        nbr /= 10;
        length--;
    }
    return (new);
}