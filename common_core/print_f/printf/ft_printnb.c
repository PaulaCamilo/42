/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:03:13 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/05 15:00:00 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printnb(int number)
{
	int		length;
	char	*str;

	str = ft_itoa(number);
	length = ft_printstring(str);
	free(str);
	return (length);
}
