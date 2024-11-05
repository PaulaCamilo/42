/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:30:15 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/04 14:30:24 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//TO PRINT STR & NB OF CHARS IN ft_printstr

void	print_nb_chrs(int n)
{
	if (n < 0)
	{
		ft_printc('-');
		n = -n;
	}
	if (n > 10)
	{
		print_nb_chrs(n / 10);
	}
	ft_printc(n % 10 + '0');
}

int	main(void)
{
	char	*str = "42 Porto";
	int		print_str = ft_printstr(str);

	ft_printc('\n');
	print_nb_chrs(print_str);
	ft_printc('\n');
	return (0);
}