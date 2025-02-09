/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:53:40 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/09 23:40:17 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;

	a = NULL;
	a = process(ac, av);
	if (a == NULL)
		return (0);
	if (checkdup(a))
	{
		free_stack(&a);
		printf("ERROR checkdup\n");
		exit(1);
		// ft_error();
	}
	if (!checksorted(a))
		sort(&a);
	free_stack(&a);
	return (0);
}
