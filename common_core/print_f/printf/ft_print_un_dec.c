/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:17:28 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/06 16:54:41 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_un_dec(unsigned int number)
{
	int	count;
	
	count = 0;
	if (number > 9)
	{
		count += ft_print_dec_int(number / 10);
		count += ft_print_dec_int(number % 10);
	}
	else if (number >= 0 && number <= 9)
		count += ft_print_char(number + '0');
	if (count < 0)
		return (-1);
	return (count);	
}

int	main(void)
{
	int	output_OG;
	int	output_FT;
	
	ft_printf("------------%%u------------\n");
	unsigned nbr_u = 42;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %u\n", 4294967295u);
	output_FT = ft_printf("FT -> %u\n", 4294967295u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = -16;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = -101;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = INT_MAX;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = INT_MIN;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = -9;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = -99;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = -10;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	return (0);
}