/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:38:16 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/08 15:25:17 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_dec_int(int number)
{
	int	count;

	count = 0;
	if (number == INT_MIN)
	{
		count = ft_string_fd("-2147483648", 1);
		if (count < 0)
			return (-1);
		return (11);
	}
	if (number < 0)
	{
		count += ft_print_char('-');
		count += ft_print_dec_int(-number);
	}
	else if (number > 9)
	{
		count += ft_print_dec_int(number / 10);
		count += ft_print_dec_int(number % 10);
	}
	else
		count += ft_print_char(number + '0');
	if (count < 0)
		return (-1);
	return (count);
}
