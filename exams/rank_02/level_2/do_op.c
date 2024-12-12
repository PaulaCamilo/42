/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:05:20 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/12 11:19:02 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		if (av[2][0] == '+')
			printf("%d", atoi(av[1]) + atoi(av[3]));
		if (av[2][0] == '-')
			printf("%d", atoi(av[1]) - atoi(av[3]));
		if (av[2][0] == '*')
			printf("%d", atoi(av[1]) * atoi(av[3]));
		if (av[2][0] == '/')
			printf("%d", atoi(av[1]) / atoi(av[3]));
		if (av[2][0] == '%')
			printf("%d", atoi(av[1]) % atoi(av[3]));
	}
	printf("\n");
	return (0);
}