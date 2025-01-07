/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:19:02 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/14 16:19:07 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tempswap;

	tempswap = *a;
	*a = *b;
	*b = tempswap;
}
