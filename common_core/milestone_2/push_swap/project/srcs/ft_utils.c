/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:03:20 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/09 23:55:18 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	ft_is_digit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

long long int	ft_atol(const char *str)
{
	int				signal;
	long long int	result;

	result = 0;
	signal = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_is_digit(*str))
			ft_error();
		result = result * 10 + (*str - 48);
		str++;
	}
	return (signal * result);
}
