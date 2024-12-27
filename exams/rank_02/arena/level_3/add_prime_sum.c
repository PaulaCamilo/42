/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:55:52 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/19 10:20:01 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *s);
int is_prime(int n);
void put_nbr(int nbr);

int ft_atoi(char *s)
{
	int res = 0;
	while (*s)
		res = res * 10 + *s++ - 48;
	return (res);
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

void put_nbr(int nbr)
{
	if (nbr >= 10)
		put_nbr(nbr / 10);
	char digit = nbr % 10 + '0';
	write (1, &digit, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int num = ft_atoi(av[1]);
		int sum = 0;
		
		while (num > 0)
		{
			if (is_prime(num))
				sum += num;
			num--;
		}
		put_nbr(sum);
	}
	if (ac != 2)
		put_nbr(0);
	write (1, "\n", 1);
	return (0);
}