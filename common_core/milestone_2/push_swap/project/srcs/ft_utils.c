/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:03:20 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/10 09:28:54 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	ft_is_digit(int n)
{
	return (n >= '0' && n <= '9');
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
