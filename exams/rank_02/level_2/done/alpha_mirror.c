/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:33:45 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/13 08:40:52 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] == 'z' || av[1][i] == 'Z')
				av[1][i] -= 25;
			else if (av[1][i] >= 'a' && av[1][i] < 'z')
				av[1][i] = ('a' + 'z') - av[1][i];
			else if (av[1][i] >= 'A' && av[1][i] < 'Z')
				av[1][i] = ('A' + 'Z') - av[1][i];
			write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}