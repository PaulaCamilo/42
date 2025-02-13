/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:02:24 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/13 14:02:51 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotate_ba(t_stack *a, t_stack *b)
{
	int		min_operations;
	int		operations;
	t_stack	*current;

	if (!a || !b)
		return (-1);
	min_operations = calc_rarrb_ba(a, b, b->value);
	current = b;
	while (current)
	{
		operations = calc_rarb_ba(a, b, current->value);
		if (operations < min_operations)
			min_operations = operations;
		operations = calc_rrarrb_ba(a, b, current->value);
		if (operations < min_operations)
			min_operations = operations;
		operations = calc_rarrb_ba(a, b, current->value);
		if (operations < min_operations)
			min_operations = operations;
		operations = calc_rrarb_ba(a, b, current->value);
		if (operations < min_operations)
			min_operations = operations;
		current = current->next;
	}
	return (min_operations);
}

int	rotate_ab(t_stack *a, t_stack *b)
{
	int		min_operations;
	int		operations;
	t_stack	*current;

	min_operations = calc_rrarrb_ab(a, b, a->value);
	current = a;
	while (current)
	{
		operations = calc_rarb_ab(a, b, current->value);
		if (operations < min_operations)
			min_operations = operations;
		operations = calc_rrarrb_ab(a, b, current->value);
		if (operations < min_operations)
			min_operations = operations;
		operations = calc_rarrb_ab(a, b, current->value);
		if (operations < min_operations)
			min_operations = operations;
		operations = calc_rrarb_ab(a, b, current->value);
		if (operations < min_operations)
			min_operations = operations;
		current = current->next;
	}
	return (min_operations);
}