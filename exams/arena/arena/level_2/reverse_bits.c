/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:32:57 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/05 19:09:29 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char revbit = 0;
    
    while (i > 0)
    {
        revbit = revbit * 2 + (octet % 2);
        octet = octet / 2;
        i--;
    }
    return (revbit);
}

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

int main()
{
	unsigned char octet = 0b00100110;
	print_bits(octet);	
	printf("\n");

	unsigned char rev = reverse_bits(octet);
	print_bits(rev);	

	return (0);
}