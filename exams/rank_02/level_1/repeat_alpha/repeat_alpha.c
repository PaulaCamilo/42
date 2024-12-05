/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:55:43 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/04 12:01:00 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	j = 1;
	if (ac == 2)
	{
		str = av[1];
		while (str[i] != '\0')
		{
			j = 1;
			if (str[i] >= 'a' && str[i] <= 'z')
				j = str[i] - 96;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				j = str[i] - 64;
			while (j >= 1)
			{
				write (1, &str[i], 1);
				j--;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}