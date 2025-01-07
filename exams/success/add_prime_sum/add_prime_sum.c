/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:57:40 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/06 13:04:40 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *s)
{
	int i = 0;
	int result = 0;
	
	while (s[i])
	{
		result = result * 10 + (s[i] - 48);
		i++;
	}
	return (result);
}

int is_prime(int n)
{
	int i = 2;

	if (n <= 1)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void put_nbr(int n)
{
	if (n > 9)
		put_nbr(n / 10);
	char digit = n % 10 + '0';
	write (1, &digit, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int nmb = ft_atoi(av[1]);
		int sum = 0;

		while (nmb > 0)
		{
			if (is_prime(nmb))
				sum += nmb;
			nmb--;
		}
		put_nbr(sum);
	}

	if (ac != 2)
		put_nbr(0);
	write (1, "\n", 1);
	return (0);
}