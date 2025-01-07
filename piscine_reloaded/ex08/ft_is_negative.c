/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:39:49 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/14 15:39:59 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char p);

void	ft_is_negative(int n)
{
	int	negative_positive;	

	if (n < 0)
	{
		negative_positive = 'N';
		ft_putchar(negative_positive);
	}
	else
	{
		negative_positive = 'P';
		ft_putchar(negative_positive);
	}
}
