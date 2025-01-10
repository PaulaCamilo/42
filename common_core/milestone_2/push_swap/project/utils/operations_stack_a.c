/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:05:28 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/10 15:13:29 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap stack a): swaps the first two elements at the top of stack a;
// Does nothing if there is only one or no elements.
void	ft_sa(t_stack_node **a, int j)
{
	t_stack_node	*temp;

	if (!*a || !((*a)->next))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (j == 0)
		write (1, "sa\n", 3);
}
