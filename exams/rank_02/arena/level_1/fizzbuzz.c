/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:05:10 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/05 08:11:43 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_n(int n)
{
	char	str[10] = "0123456789";
	if (n > 9)
		print_n(n / 10);
	write (1, &str[n % 10], 1);
}

void	fizzbuzz(void)
{
	int	i = 1;
	while (i <= 100)
	{
		if (i % 5 == 0 && i % 3 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else
			print_n(i);
		write (1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	fizzbuzz();
	return (0);
}