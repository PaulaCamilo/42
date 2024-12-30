/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:34:17 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/30 15:54:03 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long ft_atol(const char *str)
{
	int	i;
	int	signal;
	long 	count;

	i = 0;
	signal = 1;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			ft_error();
		i = i * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] > 57 || str[i] == 43 || str[i] == 45)
		ft_error();
	return (count * signal);
}