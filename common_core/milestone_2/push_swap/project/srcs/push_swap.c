/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:53:40 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/11 23:38:03 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	char	**avtemp;

	a = NULL;
	if (ac == 1)
		return (0);
	avtemp = args_parsing(ac, av);
	if (!args_val(avtemp))
		return (ft_error(), ft_free(avtemp), free_stack(&a), 0);
	if (avtemp != NULL)
		a = process(ft_arraylen(avtemp), avtemp);
	if (checkdup(a))
		return (ft_error(), ft_free(avtemp), free_stack(&a), 0);
	if (!checksorted(a))
		sort(&a);
	return (ft_free(avtemp), free_stack(&a), 0);
}
