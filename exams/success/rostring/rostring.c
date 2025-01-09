/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:33:00 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/09 12:09:26 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    int word_start;
    int word_end;
    
    if (ac >= 2)
    {
        i = 0;
        while (av[1][i])
        {
            while (av[1][i] == ' ' || av[1][i] == '\t')
                ++i;
            word_start = i;
            while (av[1][i] && !(av[1][i] == ' ' || av[1][i] == '\t'))
                ++i;
            word_end = i;
            while (av[1][i] == ' ' || av[1][i] == '\t')
                ++i;
            while (av[1][i])
            {
                if (av[1][i] && !(av[1][i] == ' ' || av[1][i] == '\t') && (av[1][i - 1] == ' ' || av[1][i - 1] == '\t'))
                {
                    while (av[1][i] && !(av[1][i] == ' ' || av[1][i] == '\t'))
                        write (1, &av[1][i++], 1);
                    write (1, " ", 1);
                }
                ++i;
            }
            while (word_start < word_end)
            {
                write (1, &av[1][word_start], 1);
                word_start++;
            }
        }
    }
    write (1, "\n", 1);
    return (0);
}