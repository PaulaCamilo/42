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

int	ft_put_hex(unsigned long number, const char format)
{
	char	*base_l;
	char	*base_u;
	int		result;

	result = 0;
	base_l = "0123456789abcdef";
	base_u = "0123456789ABCDEF";
	if (number >= 16)
	{
		result += ft_put_hex(number / 16, format);
		result += ft_put_hex(number % 16, format);
	}
	else
	{
		if (format == 'x')
			ft_putchar_fd(base_l[number], 1);
		else
			ft_putchar_fd(base_u[number], 1);
		result++;
	}
	return (result);
}