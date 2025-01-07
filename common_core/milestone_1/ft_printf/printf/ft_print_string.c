/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:06:11 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/08 15:43:57 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_string(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count = ft_string_fd("(null)", 1);
		if (count < 0)
			return (-1);
		return (6);
	}
	while (str[count])
	{
		ft_print_char(str[count]);
		count++;
	}
	if (count < 0)
		return (-1);
	return (count);
}
