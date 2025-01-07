/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:26:52 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/05 18:29:24 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit;

    while (i--)
    {
        bit = (octet >> i & 1) + '0';
        write (1, &bit, 1);
    }
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int to_print;

	if (argc == 2)
	{
		to_print = atoi(argv[1]);
		print_bits(to_print);
	}
	printf("\n");
	return (0);
}