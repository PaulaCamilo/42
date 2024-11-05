/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:35:42 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/05 14:59:51 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printstring(char *str)
{
	int	p;

	if (!str)
	{
		ft_printstring_fd("(null)", 1);
		return (6);
	}
	p = 0;
	while (str[p] != '\0')
	{
		ft_printchar(str[p]);
		p++;
	}
	return (p);
}
