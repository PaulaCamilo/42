/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:25:16 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:25:24 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int p)
{
	if (32 <= p && p <= 126)
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	a = 130;
	int b = 88;

	printf("a is printable: %d\nb is printable: %d\n",
			ft_isprint(a), ft_isprint(b));
	return (0);
}
*/
