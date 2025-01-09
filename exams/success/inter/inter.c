/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:13:56 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/09 13:16:23 by ppaula-d         ###   ########.fr       */
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
        while (av[1][i])
        {
            j = 0;
            while (av[2][j])
            {
                if (av[2][j] == av[1][i])
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