/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:11:03 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/14 13:11:15 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int n)
{
	char	*nb;
	int		lenght;

	lenght = 0;
	if (n < 0)
	{
		lenght = ft_printc(n + 48);
	}
	else
	{
		nb = ft_uitoa(n);
		lenght = ft_printstr(nb);
		free(nb);
	}
	return (lenght);
}
