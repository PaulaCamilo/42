/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:59:12 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/20 11:50:52 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	calc_rarb_ab(t_stack *a, t_stack *b, int c)
{
	int	value;

	if (!a || !b)
		return (-1);
	value = index_b(b, c);
	if (value < index_stack(a, c))
		value = index_stack(a, c);
	return (value);
}

int	calc_rrarrb_ab(t_stack *a, t_stack *b, int c)
{
	int	value;

	if (!a || !b)
		return (-1);
	value = 0;
	if (index_b(b, c))
		value = listsize(b) - index_b(b, c);
	if ((value < (listsize(a) - index_stack(a, c))) && index_stack(a, c))
		value = listsize(a) - index_stack(a, c);
	return (value);
}

int	calc_rrarb_ab(t_stack *a, t_stack *b, int c)
{
	int	value;

	if (!a || !b)
		return (-1);
	value = 0;
	if (index_stack(a, c))
		value = listsize(a) - index_stack(a, c);
	value = index_b(b, c) + value;
	return (value);
}

int	calc_rarrb_ab(t_stack *a, t_stack *b, int c)
{
	int	value;

	if (!a || !b)
		return (-1);
	value = 0;
	if (index_b(b, c))
		value = listsize(b) - index_b(b, c);
	value = index_stack(a, c) + value;
	return (value);
}
