/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:27:48 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/17 14:27:56 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int p)
{
	if ('A' <= p && p <= 'Z')
		return (p + 32);
	return (p);
}

/*
int	main(void)
{
	int	p = 66;

	printf("The lowercase of %c is: %c\n", p, ft_tolower(p));
	return (0);
}
*/