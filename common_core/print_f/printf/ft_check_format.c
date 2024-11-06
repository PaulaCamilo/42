/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:35:04 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/06 16:49:39 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_format(const char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_print_char(va_arg(args, int));
	if (type == 's')
		count += ft_print_string(va_arg(args, char *));
	if (type == 'd' || type == 'i')
		count += ft_print_dec_int(va_arg(args, int));
	if (type == 'u')
		count += ft_print_un_dec(va_arg(args, unsigned int));
	return (count);
}
