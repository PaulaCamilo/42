/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:30:05 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/09 14:36:02 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void hidenp(char *string1, char *string2)
{
    while (*string1 != '\0')
    {
        while (*string1 != *string2 && *string2 != '\0')
            ++string2;
        if (*string2 == '\0')
        {
            write (1, "0", 1);
            return;
        }
        ++string2;
        ++string1;
    }
    write (1, "1", 1);
}

int main(int ac, char **av)
{
    if (ac == 3)
        hidenp(av[1], av[2]);
    write (1, "\n", 1);
    return (0);
}