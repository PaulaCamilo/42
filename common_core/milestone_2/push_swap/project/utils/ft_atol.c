/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:34:17 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 10:54:17 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atol(const char *str)
{
	long long int	result;
	int	i;
	int	signal;

	i = 0;
	result = 0;
	signal = 1;
	
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
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((signal * result) > 2147483647 || (signal * result) < -2147483649)
		ft_error();
	return (signal * result);
}