/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:49:44 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/30 15:34:10 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *ft_nmb_sub_process(char **av)
{
	t_stack_node *a;
	char **temp;
	int i;
	int j;

	a = NULL;
	i = 0;
	temp = ft_split(av[1][i], ' ');
	while (temp[i])
	{
		j = ft_atol()
	}
}

t_stack_node *ft_nmb_process(int ac, char **av)
{
	t_stack_node *a;
	int 			i;
	int 			j;

	i = 1;
	a = NULL; //good pratice to initialize pointers to NULL to avoid segfault, since we cannot dereference pointers
	if (ac < 2)
		ft_error();
	if (ac == 2) //meaning we are working with a quoted string
		a = ft_nmb_sub_process(av);
}