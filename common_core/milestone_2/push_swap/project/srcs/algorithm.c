/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:49:44 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 11:05:20 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function does the following:
// It processes and sorts the stacks if they are passed in between quotation
// marks;
// In this case, the function takes the string, splits the elements in order
// to create separate integer numbers.
t_stack_node *ft_nbr_sub_process(char **av)
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
		j = ft_atol(temp[i]);
		ft_add_back(&a, ft_stack_new_node(j));
		i++;
	}
	ft_free_str(temp);
	free(temp);
	return (a);
}

// This function does the following:
// 1. It checks if the number of the input is less than 2;
// 2. It checks if the number of the input is equal to 2;
// 	  if it is, it means it's a quoted string and then it call another
//    function, <ft_nbr_sub_process> where you split its elements and
//    converts them to digits, so the program can process them;
// 3. It checks if the number of input is greater than 2.
//    If it is, it lists the arguments.
t_stack_node *ft_nbr_process(int ac, char **av)
{
	t_stack_node 	*a;
	int 			i;
	int 			j;

	i = 1;
	a = NULL; //good pratice to initialize pointers to NULL to avoid segfault, since we cannot dereference pointers
	if (ac < 2)
		ft_error();
	if (ac == 2) //meaning we are working with a quoted string
		a = ft_nbr_sub_process(av);
	else
	{
		while (i < ac)
		{
			j = ft_atol(av[1]);
			ft_add_back(&a, ft_stack_new_node(j));
			i++;
		}
	}
	return (a);
}