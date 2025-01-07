/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:58:15 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 11:33:28 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	struct s_stack_node *next;
	struct s_stack_node *previous;
	
}						t_stack_node;

// SOURCES

t_stack_node *ft_nbr_process(int ac, char **av);
t_stack_node *ft_nbr_sub_process(char **av);

// UTILS
char	**ft_split(char const *s, char c);

int		ft_atol(const char *str);
int		ft_checkdup_nbr(t_stack_node *a);
int 	ft_is_digit(int n);
int		ft_list_size(t_stack_node *list);
int 	ft_strlen(const char *str);

t_stack_node *ft_list_last(t_stack_node *list);
t_stack_node *ft_stack_new_node(int content);

void	ft_add_back(t_stack_node **stack, t_stack_node *stack_new);
void	ft_error(void);

// PARSING

void	ft_free_str(char **list);

#endif