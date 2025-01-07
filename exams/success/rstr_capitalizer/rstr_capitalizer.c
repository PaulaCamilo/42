/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:36:37 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 14:05:12 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int k;
	
	if (ac == 1)
		write (1, "\n", 1);
	else
	{
		i = 1;
		while (i < ac)
		{
			k = 0;
			while (av[i][k])
			{
				if (av[i][k] >= 'A' && av[i][k] <= 'Z')
					av[i][k] += 32;
				if ((av[i][k] >= 'a' && av[i][k] <= 'z') && (av[i][k + 1] == ' ' 
							|| av[i][k + 1] == '\t' || av[i][k + 1] == '\0'))
								av[i][k] -= 32;
				write (1, &av[i][k], 1);
				k++;
			}
			write (1, "\n", 1);
			i++;
		}
	}
	return (0);
}