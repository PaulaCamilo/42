/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:14:04 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/11 15:04:12 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	tempswap;
	int	p;
	int	c;

	p = 0;
	while (p < size - 1)
	{
		c = 0;
		while (c < size - p - 1)
		{
			if (tab[c] > tab[c + 1])
			{
				tempswap = tab[c];
				tab[c] = tab[c + 1];
				tab[c + 1] = tempswap;
			}
			c++;
		}
		p++;
	}
}
