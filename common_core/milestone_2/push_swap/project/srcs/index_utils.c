/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:53:06 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/11 22:29:05 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	index_stack(t_stack *stack, int target)
{
	int		stack_index;

	stack_index = 0;
	while (stack)
	{
		if (stack->value == target)
		{
			stack->index = 0;
			return (stack_index);
		}
		stack_index++;
		stack = stack->next;
	}
	return (-1);
}

int	index_b(t_stack *stack_b, int target)
{
	int		stack_index;
	t_stack	*current;

	stack_index = 1;
	if (target > stack_b->value && target < ft_listlast(stack_b)->value)
		stack_index = 0;
	else if (target > max(stack_b) || target < min(stack_b))
		stack_index = index_stack(stack_b, max(stack_b));
	else
	{
		current = stack_b->next;
		while (stack_b->value < target || current->value > target)
		{
			stack_b = stack_b->next;
			current = stack_b->next;
			stack_index++;
		}
	}
	return (stack_index);
}

int	index_a(t_stack *stack_a, int target)
{
	int		stack_index;
	t_stack	*current;

	stack_index = 1;
	if (target < stack_a->value && target > ft_listlast(stack_a)->value)
		stack_index = 0;
	else if (target > max(stack_a) || target < min(stack_a))
		stack_index = index_stack(stack_a, min(stack_a));
	else
	{
		current = stack_a->next;
		while (stack_a->value > target || current->value < target)
		{
			stack_a = stack_a->next;
			current = stack_a->next;
			stack_index++;
		}
	}
	return (stack_index);
}
