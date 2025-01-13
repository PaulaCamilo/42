/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:14:10 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/10 15:36:02 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pb (push b): if it's empty, it does nothing. Otherwise, it gets the first 
// element at the top of the stack a and puts it at the top of the stack b.
void ft_pb(t_stack_node **stack_a, t_stack_node **stack_b, int n)
{
	t_stack_node *temp;

	if (!*stack_a)
		return ;
	temp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = temp;
	if (n == 0)
		write(1, "pb\n", 3);
}