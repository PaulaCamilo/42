/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:48:48 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/28 08:20:54 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/* MAIN FUNCTION */
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);

void	add_to_stash(t_list **stash, char *buffer, int chars_read);
void	clean_stash(t_list **stash);
void	extract_line(t_list *stash, char **line);
void	read_and_stash(int fd, t_list **stash);

/* UTILS */
int		found_newline(t_list *stash);

size_t	ft_strlen(const char *str);

t_list	*get_last_node(t_list *stash);

void	free_stash(t_list *stash);
void	generate_line(char **line, t_list *stash);

#endif
