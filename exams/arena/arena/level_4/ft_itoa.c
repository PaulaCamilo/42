/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:05:21 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/19 13:58:45 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

long int_len(long n)
{
	unsigned int len = 0;
	if (n == 0)
		return (1);
	if (n < 1)
		len++;
	while (n != '\0')
	{
		len++;
		n /= 10;
	}
	return (len);
}

char *ft_itoa(int nbr)
{
	long n = nbr;
	long len = int_len(n);
	char *str = (char *)malloc(sizeof(char) * (len + 1));

	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	len--;
	while (n != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int intarr[6] = { 
			atoi(argv[1]), 42, -42, INT_MIN, INT_MAX, 0,
		};
		int n = 6;
		int i = 0;

		while (i < n)
		{
			printf("%d : %s\n", i, ft_itoa(intarr[i]));
			++i;
		}
	}
	else
		printf("Usage: ./a.out <number>\n");
	return 0;
}