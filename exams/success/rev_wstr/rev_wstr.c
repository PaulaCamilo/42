/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:07:23 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 14:30:47 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int word_start;
	int word_end;
	int i;
	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
			i++;
		while (i >= 0)
		{
			while (av[1][i] == '\0' || av[1][i] == ' ' || av[1][i] == '\t')
				i--;
			word_end = i;
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
				i--;
			word_start = i + 1;
			int flag = word_start;
			while (word_start <= word_end)
			{
				write (1, &av[1][word_start], 1);
				word_start++;
			}
			if (flag != 0)
				write (1, " ", 1);
		}
			
	}
	write (1, "\n", 1);
	return (0);
}