/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:24:24 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/11 22:24:40 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_listsize(t_stack *list)
{
	size_t	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
