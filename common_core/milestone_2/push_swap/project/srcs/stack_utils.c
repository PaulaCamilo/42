/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:14:46 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/11 22:37:58 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **list)
{
	t_stack	*temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

void	stack_new(t_stack **head, int new_data)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->value = new_data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
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
