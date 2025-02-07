/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:22:22 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/05 18:57:50 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **list)
{
	t_stack	*current;

	if (!list || !*list)
		return ;
	while (*list)
	{
		current = *list;
		*list = (*list)->next;
		current->value = 0;
		free(current);
	}
}

void	free_str(char **list)
{
	char	*current_str;

	if (!list)
		return ;
	while (*list)
	{
		current_str = *list;
		list++;
		free(current_str);
	}
	*list = NULL;
}
