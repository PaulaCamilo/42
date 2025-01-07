/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:45:59 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 15:53:07 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *s)
{
	int i = 0;
	int res = 0;
	while (s[i])
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	return (res);
}

void	print_hex(int c)
{
	char hex_digits[17] = "0123456789abcdef";
	if (c >= 16)
		print_hex(c / 16);
	write (1, &hex_digits[c % 16], 1);	
}

int main(int ac, char **av)
{	
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write (1, "\n", 1);
	return (0);	
}