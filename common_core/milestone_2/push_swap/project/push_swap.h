/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:58:15 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/27 14:16:42 by ppaula-d         ###   ########.fr       */
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

#endif