/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:55:03 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/15 09:55:04 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	pos;

	pos = 0;
	while (s1[pos] != '\0' && s2[pos] != '\0')
	{
		if (s1[pos] == s2[pos])
			pos++;
		if (s1[pos] < s2[pos] || s1[pos] > s2[pos])
			return (s1[pos] - s2[pos]);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
		{
			if (ft_strcmp(av[i], av[j]) > 0)
			{
				temp = av[i];
				av[i] = av[j];
				av[j] = temp;
			}
		}
	}
	i = 0;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
	}
	return (0);
}
