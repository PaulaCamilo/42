/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:59:27 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/09 23:53:58 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*sub_process(char **av)
{
	t_stack	*a;
	t_stack	*new_node;
	char	**tmp;
	int		i;
	long long int	value;

	a = NULL;
	i = 0;
	tmp = ft_split(av[1], ' ');
	while (tmp[i])
	{
		value = ft_atol(tmp[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			free(tmp);
			ft_error();
		}
		new_node = stack_new((int)value);
		add_back(&a, new_node);
		i++;
	}
	free_str(tmp);
	free(tmp);
	return (a);
}

t_stack	*process(int ac, char **av)
{
	t_stack	*a;
	int		i;
	long long int	value;

	i = 1;
	a = NULL;
	if (ac == 1)
		return (NULL);
	if (ac == 2)
		a = sub_process(av);
	else
	{
		while (i < ac)
		{
			value = ft_atol(av[i]);
			if (value > INT_MAX || value < INT_MIN)
			{
				free_stack(&a);
				ft_error();
			}
			add_back(&a, stack_new((int)value));
			i++;
		}
	}
	return (a);
}
