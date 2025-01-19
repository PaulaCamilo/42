/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_ba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 23:02:07 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/19 23:05:25 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_rarb_ba(t_stack *a, t_stack *b, int c)
{
	int	value;

	if (!a || !b)
		return (-1);
	
	value = index_a(a, c);
	if (value < index_stack(b, c))
		value = index_stack(b, c);
	return (value);
}

int	calc_rrarrb_ba(t_stack *a, t_stack *b, int c)
{
	int	value;

	if (!a || !b)
		return (-1);
		
	value = 0;
	if (index_a(a, c))
		value = listsize(a) - index_a(a, c);
	if ((value < (listsize(b) - index_stack(b, c))) && index_stack(b, c))
		value = listsize(b) - index_stack(b, c);
	return (value);
}

int	calc_rarrb_ba(t_stack *a, t_stack *b, int c)
{
	int	value;

	if (!a || !b)
		return (-1);
		
	value = 0;
	if (index_stack(b, c))
	value = listsize(b) - index_stack(b, c);
	value = index_a(a, c) + value;
	return (value);
}

int	calc_rrarb_ba(t_stack *a, t_stack *b, int c)
{
	int	value;

	if (!a || !b)
		return (-1);
		
	value = 0;
	if (index_a(a, c))
		value = listsize(a) - index_a(a, c);
	value = index_stack(b, c) + value;
	return (value);
}
