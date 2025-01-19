/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:59:27 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/19 22:09:24 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sub_process(char **argv)
{
	t_stack	*a;
	t_stack	*new_node;
	char	**tmp;
	int		i;
	int		value;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], ' ');
	
	while (tmp[i])
	{
		value = ft_atol(tmp[i]);
		new_node = stack_new(value);
		add_back(&a, new_node);
		i++;
	}
	
	free_str(tmp);
	free(tmp);
	return (a);
}

t_stack	*process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		value;

	i = 1;
	a = NULL;
	if (argc == 1)
		return (NULL);
	if (argc == 2)
		a = sub_process(argv);
	else
	{
		while (i < argc)
		{
			value = ft_atol(argv[i]);
			add_back(&a, stack_new(value));
			i++;
		}
	}
	return (a);
}