/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:27:55 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/08 13:08:27 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_un_dec(unsigned int number)
{
	int	count;

	count = 0;
	if (number > 9)
	{
		count += ft_print_dec_int(number / 10);
		count += ft_print_dec_int(number % 10);
	}
	else if (number >= 0 && number <= 9)
		count += ft_print_char(number + '0');
	if (count < 0)
		return (-1);
	return (count);
}
