/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:30:15 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/06 16:10:18 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

//TO PRINT CHAR SUCCESSFUL

//TO PRINT CHAR UNSUCCESSFUL, WITH ERROR RETURN

//TO PRINT STR & NB OF CHARS IN ft_printstr

void	print_nb_chrs(int n)
{
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
	}
	if (n > 10)
	{
		print_nb_chrs(n / 10);
	}
	ft_print_char(n % 10 + '0');
}

int	main(void)
{
	char	*str = "42 Porto";
	int		print_str = ft_print_string(str);

	ft_print_char('\n');
	print_nb_chrs(print_str);
	ft_print_char('\n');
	return (0);
}

//TO PRINT STR WITH ERROR RETURN

//TO PRINT A LONG NEGATIVE NUMBER

//TO PRINT A NULL POINTER WITH %p

//TO PRINT A HEXADECIMAL WITH %x OR %X