/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:29:03 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/06 00:56:30 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;
    unsigned char seen[256] = {0};

    if (ac == 3)
    {
        i = 0;
        while (av[1][i])
        {
            j = 0;
            while (av[2][j])
            {
                if (av[1][i] == av[2][j])
                {
                    if (!seen[(unsigned char)av[1][i]])
                    {
                        write (1, &av[1][i], 1);
                        seen[(unsigned char)av[1][i]] = 1;
                    }
                }
                j++;
            }
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}
