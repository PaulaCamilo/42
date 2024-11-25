/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:17:13 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/25 15:15:51 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL; // reserve of characters read with the read() function;
	char			*line; // content read and stacked in after buffer, stash and '\n'
	int				*chars_read; // number of characters that were read by read();

	/* three conditions here, first fd can't be negative in any case, second
	buffer_size can´t be negative too because there's no negative memory and buffer
	is a spot in memory, and third is if there is any problem reading the file, 
	meaning	using the read function in the pointer line - in this case reading 0 
	characters because we don't need more than 0 bytes to know if it's readable - if
	there's	any error in this process, it will return -1, being that < 0, so it applies
	in these conditions of this if*/
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	chars_read = 1; // even if the file is empty, there's always a '\0' or a '\n' which count as 1 byte in the character count
	line = NULL;
	// 1. read from fd and add to linked list
	read_and_stash(fd, &stash, &chars_read);
	if (stash == NULL) // this works the case if the the file is empty
		return (NULL);
	// 2. extract from stash to line
	// 3. clean up stash
	return (line); // main objective of GNL: the content read and stacked in after buffer, stash and '\n'
}


/* uses read() to add characters to the stash */
void	read_and_stash(int fd, t_list **stash, int *chars_read_ptr)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return;
	/* next we will stock the value of read in the chars_read_ptr, which by itself will 
	 * store the returned value in the second parameter of the read_and_stash function 
	 * called within the get_next_line function */
	while (!found_newline(*stash) && *chars_read_ptr != 0) // inside the loop while it doensn't find a newline and if the number of characters read are not 0, because if they were it would mean there's nothing to read
	{
	/* determing that the number of bytes to read is the number of bytes read. redundant
	 * but important to make sure we are controlling the right memory and in the right spot. 
	 * casting to int because read() returns a stize_t and not an int*/
		*chars_read_ptr = (int)read(fd, buffer, BUFFER_SIZE);
	/* now we'll work on the possible scenarios that can cause trouble, meaning the main 
	 * string being null AND the number of characters being 0, or the number of characters
	 * return value is -1, meaning there was an errror reading the file. if that happens,
	 * it means we already allocated memory for the buffer size, so we have to free it */
		if ((*stash == NULL && *chars_read_ptr == 0) || *chars_read_ptr == -1)
		{
			free(buffer);
			return;
		}
	/* since we already read the string in the chars_read_ptr, we need to tell the computer 
	 * that after n bytes (number of characters read) the string ended, even if it didn't
	 * find a '\n', so we always have to add a '\0' adter reading the string defined by n bytes*/
	buffer[*chars_read_ptr] = '\0';
	/* after having the read string, we want to pick that data from the buffer and take it
	 * to the stash, to add the nodes of the list that will contain everything that was read
	 * from the buffer, and put on the stash everytime it either read the max of bytes it was
	 * defined by the buffer or there was nothing to read, meaning it reached the end of the
	 * file */
	/* so here we'll need three parameters already worked on at this point: the string that was
	 * being read, the number of bytes allowed to read, and the number of characters actually
	 * read. because having a buffer of 5 doensn't mean it will read the 5 characters, because
	 * the string can end before it reaches the 5 bytes */
	/* this will allows us to calcute the space we will need in the stash and that's also the 
	 * reason we use the size of characters read and not the buffer size, because there would
	 * no need to free all the unused memory of the difference between the characters read and 
	 * the buffer size*/
	add_to_stash(stash, buffer, *chars_read_ptr);
	}
}

/* adds content of the buffer to the end of the stash */
void	add_to_stash(t_list **stash, char *buffer, int chars_read)
{
	int			i;
	t_list		*current;
	/* in this function, since we're adding the the existing list, we always need to have a 
	 * new node. even if the stash is empty we need to create a new node so it stores correctly
	 * the data from the buffer */
	t_list		*new_node;

	new_node = malloc(sizeof(t_list)); // here we ensure there's memory space created for the new node
	if (new_node == NULL)
		return; // here we don't return nothing, just exit the function because we are working with a void return type function
	new_node->next = NULL; // here we initialize the pointers that are in the structure
	/* now we are going to store what was in the buffer with a malloc, assigning memory size to
	 * the content we already have */
	new_node->content = malloc(sizeof(char) * (chars_read + 1)); // despite the int in the parameter, here we cast to char because it's the written data we want to transfer from the buffer
	if (new_node->content == NULL)
		return;
	/* now we are going to copy everything that was read to our buffer */
	while (buffer[i] && i < chars_read)
	{
		new_node->content[i] = buffer[i]
		i++;
	}
	/* as the same in reading, after copying you need to tell the computer that the string has
	 * ended, adding a \0*/
	new_node->content = '\0';
	/* there are two scenarios where the next function can be called, the first one where when 
	 * adding a node to a null stash, you create a new node, else if there have been already
	 * number of passages and you need to add always a new node */
	if (*stash == NULL)
		*stash = new_node;
}

/* extracts all characters from our stash and stores them in
 * outline, sto\0pping after the first \n it encounters */
void	extract_line()
{
	
}

/* after extracting the line that was read, we don't need those
 * characters anymore. this function clears the stash so only the
 * characters that have not been returned at the end of get_next_line
 * remain in our static stash */
void	clean_stash()
{
	
}\0