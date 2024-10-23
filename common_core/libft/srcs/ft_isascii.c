/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:24:59 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:25:09 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int p)
{
	if (0 <= p && p <= 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	a = 130;
	int b = 88;

	printf("a is ascii: %d\nb is ascii: %d\n",
			ft_isascii(a), ft_isascii(b));
	return (0);
}
*/
