/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:29:46 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 13:34:56 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int j;
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