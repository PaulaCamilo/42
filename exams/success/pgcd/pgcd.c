/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:46:46 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 14:54:15 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int a;
	int b;
	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		
		if ((a > 0) && (b > 0))
		{
			while (a != b)
			{
				if (a > b)
					a -= b;
				else
					b -= a;
			}
			printf("%d", a);
		}
	}
	printf("\n");
	return (0);
}