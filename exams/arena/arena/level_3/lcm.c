/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:21:40 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/19 11:23:55 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int i = 0;
	
	if (a == 0 || b = 0)
		return (0);
	if (a < b)
		i = a;
	else
		i = b;
	while (1)
	{
		if (i % a == 0 && i % b == 0)
			return (i);
		++i;
	}
}