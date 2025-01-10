/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:10:25 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/10 12:55:39 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here we free the stack after sorting it.

void	ft_free_stack(t_stack_node **list)
{
	t_stack_node *temp;

	if (!list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		(*list)->value = 0;
		free(*list);
		*list = temp;
	}
}