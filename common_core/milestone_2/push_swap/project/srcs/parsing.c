/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:59:27 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/11 20:58:37 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char **args_parsing(int ac, char **av)
{
    char **avtemp;
    int i;
    int j;

    if (ac == 2)
        return ft_split(av[1], ' ');

    avtemp = (char **)malloc(ac * sizeof(char *));
    i = 0;
    j = 0;
    while (++i < ac)
    {
        avtemp[j] = ft_strdup(av[i]);
        j++;
    }
    avtemp[j] = NULL;
    return avtemp;
}

int args_val(char **avtemp)
{
    int i;
    int j;

    i = 0;
    while (i < ft_arraylen(avtemp))
    {
        j = 0;
        while (avtemp[i] && avtemp[i][j])
        {
            if (ft_isdigitplussign(avtemp[i][j]) == 0
                || ((avtemp[i][0] == '-' || avtemp[i][0] == '+')
                    && ft_strlen(avtemp[i]) == 1)
                || avtemp[i][j + 1] == '-' || avtemp[i][j + 1] == '+')
            {
                return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}

t_stack	*process(int ac, char **av)
{	
	t_stack			*a;
	int				i;
	long	value;

	i = 0;
	a = NULL;
		while (i < ac)
		{
			value = ft_atol(av[i]);
			if (value > INT_MAX || value < INT_MIN)
			{
				free_stack(&a);
				ft_error();
				break ;
			}
			stack_new(&a, (int)value);
			i++;
		}
	return (a);
}
