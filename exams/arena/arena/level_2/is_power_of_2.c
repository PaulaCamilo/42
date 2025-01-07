/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:45:31 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/05 17:50:06 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	    is_power_of_2(unsigned int n)
{
	return (n && !(n & (n - 1)));
}

#include <stdio.h>

int main(void)
{
	unsigned int n[3] = { 4, 1024, 40 };
	int res;
	int i;

	i = 0;
	res = 0;
	while (i < 3)
	{
		res = is_power_of_2(n[i]);
		printf("n = %d => %d\n", n[i], res);
		++i;
	}
	
	return (0);
}