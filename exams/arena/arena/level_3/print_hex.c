/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:44:47 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/19 11:49:16 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *s);
int print_hex(int c);

int ft_atoi(char *s)
{
	int n = 0;
	while (*s)
	{
		n = n * 10;
		n = n + *s - 48;
		++s;
	}
	return (n);
}

int print_hex(int c)
{
	char hex_digits[] = "0123456789abcdef";
	if (c >= 16)
		print_hex(c / 16);
	write (1, &hex_digits[c % 16], 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write (1, "\n", 1);
}