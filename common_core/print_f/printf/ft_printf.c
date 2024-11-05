/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:04:36 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/05 12:43:24 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_conversions(va_list args, const char converter)
{
	int	length;

	length = 0;
	if (converter == 'c')
			length += ft_printc(va_arg(args, int));
	else if (converter == 's')
			length += ft_printstr(va_arg(args, char *));
	else if (converter == 'p')
			length += ft_printptr(va_arg(args, unsigned long));
	else if (converter == '')
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		p;
	va_list args;
	int		length;

	p = 0;
	length = 0;
	va_start(args, str);
	while (str[p] != '\0')
	{
		if (str[p] == '%')
		{
			length += ft_conversions(args, str[p + 1]);
			p++;
		}
		else
			length += ft_printc(str[p]);
		p++;
	}
	va_end(args);
	return (length);
}
