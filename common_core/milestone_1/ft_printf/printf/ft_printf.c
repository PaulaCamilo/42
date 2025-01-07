/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:29:52 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/12 09:23:41 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *var, ...)
{
	int			i;
	int			count;
	va_list		args;

	va_start(args, var);
	i = 0;
	count = 0;
	while (var[i])
	{
		if (var[i] == '%')
		{
			i++;
			count += ft_check_format(var[i], args);
		}
		else
			count += ft_print_char(var[i]);
		i++;
	}
	va_end (args);
	if (count < 0)
		return (-1);
	return (count);
}
