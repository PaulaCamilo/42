/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:14:46 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/09 18:09:10 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (!stack)
		return ;
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = listlast(*stack);
		last_node->next = new_node;
	}
}

t_stack	*stack_new(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof (t_stack));
	if (!new_node)
		return (0);	
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}

int	checkdup(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;

	while (a)
	{
		current = a->next;
		compare = current;
		while (compare)
		{
			if (a->value == compare->value)
				return (1);
			compare = compare->next;
		}
		a = a->next;
	}
	return (0);
}

int	checksorted(t_stack *stack_a)
{
	int	prev_value;

	if (!stack_a)
		return (1);
	prev_value = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (prev_value > stack_a->value)
			return (0);
		prev_value = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}
