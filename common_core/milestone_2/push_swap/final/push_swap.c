/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:53:40 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/19 21:57:55 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    main(int argc, char **argv)
{
    t_stack	*a;
	
    a = process(argc, argv);
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