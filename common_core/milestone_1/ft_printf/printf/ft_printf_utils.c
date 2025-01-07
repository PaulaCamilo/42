/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:12:50 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/12 09:13:54 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_base16(unsigned long number, char *base)
{
	int	count;

	count = 0;
	if (number > 15)
	{
		count += ft_base16((number / 16), base);
		count += ft_base16((number % 16), base);
	}
	else
		count += ft_print_char(base[number]);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_char_fd(char c, int fd)
{
	return (write (fd, &c, 1));
}

int	ft_string_fd(char *str, int fd)
{
	return (write (fd, str, ft_strlen(str)));
}

int	ft_strlen(char *str)
{
	int	p;

	p = 0;
	while (str[p])
		p++;
	return (p);
}
