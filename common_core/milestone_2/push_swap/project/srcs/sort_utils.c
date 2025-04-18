/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:31:28 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/11 22:29:19 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (min(*stack_a) == first)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (max(*stack_a) == first)
	{
		ra(stack_a, 0);
		if (!checksorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (index_stack(*stack_a, max(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}

void	sort_b_until_three(t_stack **stack_a, t_stack **stack_b)
{
	int		min_op;
	t_stack	*cur;

	while (ft_listsize(*stack_a) > 3 && !checksorted(*stack_a))
	{
		cur = *stack_a;
		min_op = rotate_ab(*stack_a, *stack_b);
		while (min_op >= 0)
		{
			if (min_op == calc_rarb_ab(*stack_a, *stack_b, cur->value))
				min_op = execute_rarb(stack_a, stack_b, cur->value, 'a');
			else if (min_op == calc_rrarrb_ab(*stack_a, *stack_b, cur->value))
				min_op = execute_rrarrb(stack_a, stack_b, cur->value, 'a');
			else if (min_op == calc_rarrb_ab(*stack_a, *stack_b, cur->value))
				min_op = execute_rarrb(stack_a, stack_b, cur->value, 'a');
			else if (min_op == calc_rrarb_ab(*stack_a, *stack_b, cur->value))
				min_op = execute_rrarb(stack_a, stack_b, cur->value, 'a');
			else
				cur = cur->next;
		}
	}
}

t_stack	*sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (ft_listsize(*stack_a) > 3 && !checksorted(*stack_a))
	{
		pb (stack_a, &stack_b, 0);
		if (checksorted(stack_b))
			break ;
	}
	if (ft_listsize(*stack_a) > 3)
		sort_b_until_three(stack_a, &stack_b);
	if (!checksorted(*stack_a))
		sort_three(stack_a);
	return (stack_b);
}

t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		min_op;
	t_stack	*cur;

	while (*stack_b)
	{
		cur = *stack_b;
		min_op = rotate_ba(*stack_a, *stack_b);
		while (min_op >= 0)
		{
			if (min_op == calc_rarb_ba(*stack_a, *stack_b, cur->value))
				min_op = execute_rarb(stack_a, stack_b, cur->value, 'b');
			else if (min_op == calc_rarrb_ba(*stack_a, *stack_b, cur->value))
				min_op = execute_rarrb(stack_a, stack_b, cur->value, 'b');
			else if (min_op == calc_rrarrb_ba(*stack_a, *stack_b, cur->value))
				min_op = execute_rrarrb(stack_a, stack_b, cur->value, 'b');
			else if (min_op == calc_rrarb_ba(*stack_a, *stack_b, cur->value))
				min_op = execute_rrarb(stack_a, stack_b, cur->value, 'b');
			else
				cur = cur->next;
		}
	}
	return (stack_a);
}

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		min_index;
	int		stack_size;

	stack_b = NULL;
	if (ft_listsize(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
		min_index = index_stack(*stack_a, min(*stack_a));
		stack_size = ft_listsize(*stack_a);
		if (min_index < ft_listsize(*stack_a) - min_index)
		{
			while ((*stack_a)->value != min(*stack_a))
				ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->value != min(*stack_a))
				rra(stack_a, 0);
		}
	}
}
