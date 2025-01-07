/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:48:11 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/06 00:52:27 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int i = 0;
        int j = 0;
        unsigned char seen[256] = {0};
        
        while (av[1][i])
        {
            if (!seen[(unsigned char)av[1][i]])
            {
                write (1, &av[1][i], 1);
                seen[(unsigned char)av[1][i]] = 1;
            }
            i++;
        }
        while (av[2][j])
        {
            if (!seen[(unsigned char)av[2][j]])
            {
                write (1, &av[2][j], 1);
                seen[(unsigned char)av[2][j]] = 1;
            }
            j++;
        }
    }
    write (1, "\n", 1);
    return (0);
}