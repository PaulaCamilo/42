/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdup_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:15:20 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 11:17:11 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here we'll check if the stack contains any duplicate numbers
int	ft_checkdup_nbr(t_stack_node *a)
{
	t_stack_node *temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->value == temp->value)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}