/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:04:27 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/11 11:23:10 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	p;
	int	c;
	int	tempswap;

	p = 0;
	c = size - 1;
	while (p < (size / 2))
	{
		tempswap = tab[p];
		tab[p] = tab[c];
		tab[c] = tempswap;
		p++;
		c--;
	}
}
