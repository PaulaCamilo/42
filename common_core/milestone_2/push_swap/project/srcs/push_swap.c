/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:53:40 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/10 00:30:46 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_numeric(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_is_digit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
int	main(int ac, char **av)
{
	t_stack	*a;
	int i;
	
	a = NULL;
	if (ac == 1)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (!is_numeric(av[i]))
			ft_error();
		i++;
	}
	a = process(ac, av);
	if (a == NULL)
		return (0);
	if (checkdup(a))
	{
		free_stack(&a);
		ft_error();
	}
	if (!checksorted(a))
		sort(&a);
	free_stack(&a);
	return (0);
}
