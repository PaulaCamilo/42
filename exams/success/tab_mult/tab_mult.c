/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:18:49 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/06 13:36:33 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *s)
{
	int i = 0;
	int result = 0;
	int sign = 1;
	
	while (s[i] == ' ' || s[i] <= 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

void put_nbr(int n)
{
	if (n > 9)
		put_nbr(n /10);
	char digit = n % 10 + '0';
	write (1, &digit, 1);
}

int main(int ac, char **av)
{
	int i;
	int num;
	
	if (ac == 2)
	{
		i = 1;
		num = ft_atoi(av[1]);
		while (i <= 9)
		{
			put_nbr(i);
			write (1, " x ", 3);
			put_nbr(num);
			write (1, " = ", 3);
			put_nbr(i * num);
			write (1, "\n", 1);
			i++;
		}	
	}
	else
		write (1, "\n", 1);
	return (0);
}