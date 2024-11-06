/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:12:50 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/06 15:16:45 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strlen(char *str)
{
	int	p;

	p = 0;
	while (str[p])
		p++;
	return (p);
}

int	ft_string_fd(char *str, int fd)
{
	return (write (fd, str, ft_strlen(str)));
}