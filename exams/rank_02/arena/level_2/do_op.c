/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:38:13 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/16 14:41:47 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
	printf ("\n");
	return (0);
}