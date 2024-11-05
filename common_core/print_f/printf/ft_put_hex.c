/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:34:46 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/04 15:40:38 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_put_hex(unsigned long number, const char form)
{
	char	*base_u;
	char	*base;
	int		result;

	result = 0;
	base = "0123456789abcdef";
	base_u = "0123456789ABCDEF";
	if (number >= 16)
	{
		result += ft_put_hex(number / 16, form);
		result += ft_put_hex(number % 16, form);
	}
	else
	{
		if (form == 'x')
			ft_putchar_fd(base[number], 1);
		else
			ft_putchar_fd(base_u[number], 1);
		result++;
	}
	return (result);
}