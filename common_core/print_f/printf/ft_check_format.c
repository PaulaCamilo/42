/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:35:04 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/08 15:37:13 by ppaula-d         ###   ########.fr       */
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
	if (type == 'x' || type == 'X')
		count += ft_print_hexa(va_arg(args, unsigned int), type);
	if (type == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	else if (type == '%')
		count += ft_print_char('%');
	return (count);
}
