/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 23:06:36 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/19 23:12:26 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_rarb(t_stack **a, t_stack **b, int target, char id_stack)
{
	if (id_stack == 'a')
	{
		while ((*a)->value != target && index_b(*b, target) > 0)
			rr(a, b, 0);
		while ((*a)->value != target)
			ra(a, 0);
		while (index_b(*b, target) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != target && index_a(*a, target) > 0)
			rr(a, b, 0);
		while ((*b)->value != target)
			rb(b, 0);
		while (index_a(*a, target) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	execute_rrarrb(t_stack **a, t_stack **b, int target, char id_stack)
{
	if (id_stack == 'a')
	{
		while ((*a)->value != target && index_b(*b, target) > 0)
			rrr(a, b, 0);
		while ((*a)->value != target)
			rra(a, 0); 
		while (index_b(*b, target) > 0)
			rrb(b, 0); 
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != target && index_a(*a, target) > 0)
			rrr(a, b, 0);
		while ((*b)->value != target)
			rrb(b, 0);
		while (index_a(*a, target) > 0)
			rra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	execute_rrarb(t_stack **a, t_stack **b, int target, char id_stack)
{
	if (id_stack == 'a')
	{
		while ((*a)->value != target)
			rra(a, 0);
		while (index_b(*b, target) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (index_a(*a, target) > 0)
			rra(a, 0);
		while ((*b)->value != target)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	execute_rarrb(t_stack **a, t_stack **b, int target, char id_stack)
{
	if (id_stack == 'a')
	{
		while ((*a)->value != target)
			ra(a, 0);
		while (index_b(*b, target) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (index_a(*a, target) > 0)
			ra(a, 0);
		while ((*b)->value != target)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}
