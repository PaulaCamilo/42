/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:23:19 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/13 13:34:38 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	int k = 0;
	int l = 0;
	char *s1;
	char *s2;

	if (ac == 3)
	{
		s1 = av[1];
		s2 = av[2];
		while (s1[i] != '\0')
		{
			k = 0;
			while (s2[k] != '\0')
			{
				if (s1[i] == s2[k])
				{
					l = 0;
					while (s1[l] != s1[i])
						l++;
					if (l == i)
					{
						l = 0;
						while (s2[l] != s2[k])
							l++;
						if (l == k)
							write (1, &s1[i], 1);
					}
				}
				k++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}