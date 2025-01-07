/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_nbrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:22:38 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 12:13:57 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here we sort the stack_a to check if there are more than two elements in
// the stack_a;
// If there are, it makes the final sort in stack_a after all values were
// pushed to stack_b, sorted and pushed back to stack_a;
// This is because even if the stack_a is sorted at the end, the minimum
// number have to be at the top of the stack_a, so it simply brings the
// the smallest number of the stack_a to the top.

void	ft_sort_stack_a(t_stack_node **stack_a)
{
	t_stack_node 	*stack_b;
	int				i;

	stack_b = NULL; //good pratice to initialize pointers to NULL to avoid segfault, since we cannot dereference pointers
	if (ft_list_size(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = 
	}
}

t_stack_node