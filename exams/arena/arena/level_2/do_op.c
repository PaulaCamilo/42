/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:29:04 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/03 16:37:20 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 4)
    {
        if (av[2][0] == '+')
            printf("%d", (atoi(av[1]) + atoi(av[3])));
        if (av[2][0] == '-')
            printf("%d", (atoi(av[1]) - atoi(av[3])));
        if (av[2][0] == '*')
            printf("%d", (atoi(av[1]) * atoi(av[3])));
        if (av[2][0] == '/')
            printf("%d", (atoi(av[1]) / atoi(av[3])));
        if (av[2][0] == '%')
            printf("%d", (atoi(av[1]) % atoi(av[3])));
    }
    printf("\n");
    return (0);
}