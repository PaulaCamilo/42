/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:26:41 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/26 13:08:53 by ppaula-d         ###   ########.fr       */
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

// frees the entire stash after creating the new node with the remaing characters after a newline was found
void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content); // we need this because everytime we allocated memory to the string of the content
		next = current->next; // but yet we need to keep a pointer to the next element, next node
		free(current); // yet we need to free that pointer after it was used, that's what it does here
		current = next; // here we point the current content to the nodes we already saved after the first free of this function
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

/* calculates the number of chars in the current line, including the trailing \n if there is one
 * and allocates memory accordingly */
void	generate_line(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}