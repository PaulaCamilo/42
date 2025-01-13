/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:07:01 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/10 12:56:08 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack_node	*a;

	a = ft_nbr_process(ac, av);
	if (!a || ft_checkdup_nbr(a))
	{
		ft_free_str(&a);
		ft_error();
	}
	if (!ft_check_sorted_nbr(a))
		ft_sort_nbrs(&a);
	ft_free_stack(&a);
	return (0);
}