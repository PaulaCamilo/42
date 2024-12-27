/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:33:38 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/19 11:41:40 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char n1;
	char n2;

	if (ac == 3)
	{
		if ((n1 == atoi(av[1])) > 0 && n2 == atoi(av[2]) > 0)
		{
			while (n1 != n2)
			{
				if (n1 > n2)
					n1 -= n2;
				else
					n2 -= n1;
			}
			printf("%d", n1);
		}
	}
	printf("\n", 1);
	return (0);
}
