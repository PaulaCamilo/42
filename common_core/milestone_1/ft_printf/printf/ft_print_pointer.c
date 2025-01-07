/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:31:00 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/12 09:08:59 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_pointer(void *ptr)
{
	int				count;
	char			*base_l;
	unsigned long	ptr_a;

	if (!ptr)
	{
		count = ft_string_fd("(nil)", 1);
		if (count < 0)
			return (-1);
		return (5);
	}
	ptr_a = (unsigned long) ptr;
	base_l = "0123456789abcdef";
	count = 0;
	count += ft_print_string("0x");
	count += ft_base16(ptr_a, base_l);
	return (count);
}
