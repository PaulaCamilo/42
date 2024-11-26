/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:17:13 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/26 13:10:43 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL; // reserve of characters read with the read() function;
	char			*line; // content read and stacked in after buffer, stash and '\n'

	/* three conditions here, first fd can't be negative in any case, second
	buffer_size can´t be negative too because there's no negative memory and buffer
	is a spot in memory, and third is if there is any problem reading the file, 
	meaning	using the read function in the pointer line - in this case reading 0 
	characters because we don't need more than 0 bytes to know if it's readable - if
	there's	any error in this process, it will return -1, being that < 0, so it applies
	in these conditions of this if*/
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	// 1. read from fd and add to linked list
	read_and_stash(fd, &stash);
	if (stash == NULL) // this works the case if the the file is empty
		return (NULL);
	// 2. extract from stash to line
	extract_line(stash, &line); // since we are not going to modify the stash, we don't need to address, opposite to the line which we will change it so we need to change its memory address
	// 3. clean up stash
	clean_stash(&stash); // here we need to address our stash because we are going to clean all the content generated until here, modifying its memory
	if (line[0] == '\0') // finally, when there is nothing more to read, we free and null to tell the computer it's over and there's nothing more to read
	{
		free_stash(stash);
		stash = NULL;
		free (line);
		return (NULL);
	}
	return (line); // main objective of GNL: the content read and stacked in after buffer, stash and '\n'
}


/* uses read() to add characters to the stash */
void	read_and_stash(int fd, t_list **stash)
{
	char	*buffer;
	int 	chars_read; // number of characters that were read by read();

	chars_read = 1;
	while (!found_newline(*stash) && chars_read != 0) // inside the loop while it doensn't find a newline and if the number of characters read are not 0, because if they were it would mean there's nothing to read
	{
		/* having the malloc inside the loop, we can then free the memory used by the read
		 * function, having the memory allocation more controled*/
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return;
	/* next we will stock the value of read in the chars_read, which by itself will 
	 * store the returned value in the second parameter of the read_and_stash function 
	 * called within the get_next_line function */
	
	/* determing that the number of bytes to read is the number of bytes read. redundant
	 * but important to make sure we are controlling the right memory and in the right spot. 
	 * casting to int because read() returns a stize_t and not an int*/
		chars_read = (int)read(fd, buffer, BUFFER_SIZE);
	/* now we'll work on the possible scenarios that can cause trouble, meaning the main 
	 * string being null AND the number of characters being 0, or the number of characters
	 * return value is -1, meaning there was an errror reading the file. if that happens,
	 * it means we already allocated memory for the buffer size, so we have to free it */
		if ((*stash == NULL && chars_read == 0) || chars_read == -1)
		{
			free(buffer);
			return;
		}
	/* since we already read the string in the chars_read, we need to tell the computer 
	 * that after n bytes (number of characters read) the string ended, even if it didn't
	 * find a '\n', so we always have to add a '\0' adter reading the string defined by n bytes*/
		buffer[chars_read] = '\0';
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
		add_to_stash(stash, buffer, chars_read);
		free(buffer);	
	}
}

/* adds content of the buffer to the end of the stash */
void	add_to_stash(t_list **stash, char *buffer, int chars_read)
{
	int			i;
	t_list		*last; // last element of the stash
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
	/* now we are going to copy everything that was read to our buffer, so we need to initalize
	 * the index so it starts copying from the beggining */
	i = 0;
	while (buffer[i] && i < chars_read)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	/* as the same in reading, after copying you need to tell the computer that the string has
	 * ended, adding a \0*/
	new_node->content[i] = '\0';
	/* there are two scenarios where the next function can be called, the first one where when 
	 * adding a node to a null stash, you create a new node, else if there have been already
	 * number of passages and you need to add always a new node */
	if (*stash == NULL)
	{
		*stash = new_node;
		return;
	}
	last = get_last_node(*stash); // this means the last element of the stash is the last element of the list, being the last node
	last->next = new_node; // here, it creates a new node with the last element
}

/* extracts all characters from our stash and stores them in
 * outline, stopping after the first \n it encounters */
void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j; // we need two indexes

	if (stash == NULL)
		return;
	generate_line(line, stash); // allocates enough memory to get the new line extracted. this line parameter sends the info directly to the pointer on the get_net_line main function
	if (*line == NULL)
		return; // it's here that we check if the line is NULL and not in the generate_line function, because we already saved memory space of the pointer of the pointer and in this function we are not modifying th eline, we are just generating space in the memory for it to be created. so it's on the function that's it's created that you have to check if the line is empty or not, because that's where you are going to modify its memory
	j = 0;
	while (stash) // we go through our stash again
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n') // if the content on i is equal to '\n'
			{
				(*line)[j++] = stash->content[i]; // we are going to put that content in the place it should be, therefor we need the two indexes, because the i is for the original content and j is for the new line with the new content
				break;
			}
			(*line)[j++] = stash->content[i++]; // if the i content is not equal to '\n', it increments and copies normally
		}
		stash = stash->next;
	}
	(*line)[j] = '\0'; // never forget to close the new line
}

/* after extracting the line that was read, we don't need those
 * characters anymore. this function clears the stash so only the
 * characters that have not been returned at the end of get_next_line
 * remain in our static stash */
void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int				i;
	int				j;

	clean_node = malloc(sizeof(t_list)); // here we right away allocate memory for the new cleaned space in the memory
	if (stash == NULL || clean_node == NULL) // if one of them is NULL we exit the function
		return;
	clean_node->next = NULL;
	last = get_last_node(*stash); // here we dereference our stash to send it and get the pointer to the last element
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n') // so we get the true size of last->content
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1)); // here we allocate memory for the content read after the new line and clean everything before the new line character
	if (clean_node->content == NULL) // so there is no chance to change memory that hasn't been allocated
		return;
	j = 0; // we initialize so we start from we were before
	while(last->content[i])
		clean_node->content[j++] = last->content[i++]; // so increment in the same line since they are used at the same time. this also means that it copies everything from i to j that hasn't been returned before, meaning it's the data that was saved in the static memory after a '\n'was found
	clean_node->content[j] = '\0';
	free_stash(*stash); // in the clean_stash, by clean it means it takes the data that hasn't been returned before into a new node. so this means that in the original stash there is memory space that needs to be freed, so that's the point of this free_stash function
	*stash = clean_node; // here the updated stash will now point to the new and updated clean_node
}