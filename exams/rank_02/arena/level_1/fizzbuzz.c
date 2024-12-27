/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:20:40 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/16 13:26:34 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_number(int n)
{
	char str[10] = "0123456789";
	if (n > 9)
		print_number(n / 10);
	write (1, &str[n % 10], 1);
}

void fizzbuzz(void)
{
	int n = 1;
	while (n <= 100)
	{
		if (n % 5 == 0 && n % 3 == 0)
			write (1, "fizzbuzz", 8);
		else if (n % 5 == 0)
			write (1, "buzz", 4);
		else if (n % 3 == 0)
			write (1, "fizz", 4);
		else
			print_number(n);
		write (1, "\n", 1);
		n++;
	}	
}

int main(void)
{
	fizzbuzz();
	return (0);
}