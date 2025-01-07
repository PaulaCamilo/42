/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_quoted_args.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:55:34 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 11:02:04 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PARSING

// Here we free the string which has the integers values in between quotes,
// after allocating its memory with the temp variable in the case of quoted
// arguments

void	ft_free_str(char **list)
{
	char *nbr1;

	if (!list)
		return ;
	while (*list)
	{
		nbr1 = *list;
		list++;
		free(nbr1);
	}
	*list = NULL;
}