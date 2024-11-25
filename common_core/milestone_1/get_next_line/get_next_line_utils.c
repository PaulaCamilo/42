/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:26:41 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/25 14:43:28 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// looks for a newline character in the giver linked list
int	found_newline(t_list *stash)
{
	int		i;
	t_list	*current;

	// opposite to the mains, in the booleans 0 means no, and 1 means yes
	if (stash == NULL) // indicating the read_and_stash function that there's nothing to look for, so it returns 0
		return (0);
	current = get_last_node(stash);
	// having the need to go through the last node, we initialize our index
	i = 0;
	// while having something inside our string
	while (current->content[i])
	{
		// if we find a new line within our string, we leave the loop and return (1), saying yes
		if (current->content[i] == '\n')
			return (1);
		// else we increment until we find a newline
		i++;
	}
	// if we get to this point on the loop, it means we didn't find a '\n', so we return (0) saying no
	return (0);
}

// returns a pointer to last node in our stash, which contains our list
t_list	*get_last_node(t_list *stash)
{
	t_list	*current;
	
	current = stash;
	// here we'll determine that the current node is always the last one, starting to work from the last one and not from the first
	while (current && current->next)
		current = current->next;
	return (current);
}