/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:47:04 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/13 13:52:55 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int ascii [255] = {0};
		int i = 1;
		int j;
		
		while (i <= 2)
		{
			j = 0;
			while (av[i][j])
			{
				if (ascii[(int)av[i][j]] == 0)
				{
					ascii[(int)av[i][j]] = 1;
					write (1, &av[i][j], 1);
				}
				j++;
			}			
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}