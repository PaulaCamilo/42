/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:58:15 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/30 11:03:36 by ppaula-d         ###   ########.fr       */
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

t_stack_node *ft_nmb_process(int ac, char **av);
t_stack_node *ft_nmb_sub_process(char **av);

#endif