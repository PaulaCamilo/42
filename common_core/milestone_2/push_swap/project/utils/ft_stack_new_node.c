/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:20:47 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 10:25:29 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here we are going to create a new stack node with the given number by
// the <ft_add_back> function, allocating its memory accordingly

t_stack_node *ft_stack_new_node(int content)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		ft_error();
	new->value = content;
	new->next = NULL;
	return (new);
}