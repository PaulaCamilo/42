/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:07:25 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 11:34:02 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here we return the last element of the stack, making reference to the
// back side, the bottom of the stack
t_stack_node *ft_list_last(t_stack_node *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

// Here we determine a return the size of the stack.
int	ft_list_size(t_stack_node *list)
{
	size_t	i;
	
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}