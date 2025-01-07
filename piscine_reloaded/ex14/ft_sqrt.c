/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:02:22 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/15 09:02:24 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	index;
	long	counter;

	counter = nb;
	if (counter <= 0)
		return (0);
	if (counter == 1)
		return (1);
	index = 2;
	if (counter >= 2)
	{
		while (index * index <= counter)
		{
			if (index * index == counter)
				return (index);
			index++;
		}
	}
	return (0);
}
