/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:22:38 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/10 13:49:38 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Here we push all the elements from stack_a to stack_b until there are
// only three elements in stack_a. While pushing, we make sure it is sorting
// correctly in stack_b. When we finally have three elements in stack_a, we
// call the function sort_three to sort the left over elements in stack_a.
t_stack_node *ft_sort_b(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	if (ft_list_size(*stack_a) > 3 && !ft_check_sorted_stack(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_list_size(*stack_a) > 3 && !ft_check_sorted_stack(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_list_size(*stack_a) > 3 && !ft_check_sorted_stack(*stack_a))

	
}

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
		stack_b = ft_sort_b(stack_a);
	}
}
