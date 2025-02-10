/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:53:56 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/10 09:33:13 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

typedef struct s_stack
{
	long			value;
	long			index;
	struct s_stack	*next;
}	t_stack;

// ft_utils.c
long long int	ft_atol(const char *str);
int				is_numeric(char *str);
void			ft_error(void);
int				ft_is_digit(int n);

// ft_utils_2.c
int				ft_strlen(const char *str);
char			**ft_split(char const *s, char c);

// algorithm.c
t_stack			*sub_process(char **argv);
t_stack			*process(int argc, char **argv);

// list_utils.c
t_stack			*listlast(t_stack *list);
int				listsize(t_stack *list);
int				min(t_stack *a);
int				max(t_stack *a);

// stack_utils.c
void			add_back(t_stack **stack, t_stack *new_node);
t_stack			*stack_new(int content);
int				checkdup(t_stack *a);
int				checksorted(t_stack *stack_a);

// free_utils.c
void			free_stack(t_stack **list);
void			free_str(char **list);

// sort_utils.c
void			sort_three(t_stack **stack_a);
void			sort_b_until_three(t_stack **stack_a, t_stack **stack_b);
t_stack			*sort_b(t_stack **stack_a);
t_stack			**sort_a(t_stack **stack_a, t_stack **stack_b);
void			sort(t_stack **stack_a);

// operations_stack_a.c
void			ra(t_stack **a, int j);
void			sa(t_stack **a, int j);
void			pa(t_stack **a, t_stack **b, int j);
void			rra(t_stack **a, int j);

// operations_stack_b.c
void			pb(t_stack **stack_a, t_stack **stack_b, int j);
void			rrb(t_stack **b, int j);
void			rb(t_stack **b, int j);

// operations_both_stacks.
void			rr(t_stack **a, t_stack **b, int j);
void			rrr_cont(t_stack **b, int j);
void			rrr(t_stack **a, t_stack **b, int j);

// index_utils.c
int				index_stack(t_stack *stack, int target);
int				index_b(t_stack *stack_b, int target);
int				index_a(t_stack *stack_a, int target);

// rotation_type.c
int				rotate_ba(t_stack *a, t_stack *b);
int				rotate_ab(t_stack *a, t_stack *b);

// costs_ab.c
int				calc_rarb_ab(t_stack *a, t_stack *b, int c);
int				calc_rrarrb_ab(t_stack *a, t_stack *b, int c);
int				calc_rrarb_ab(t_stack *a, t_stack *b, int c);
int				calc_rarrb_ab(t_stack *a, t_stack *b, int c);

// costs_ba.c
int				calc_rarb_ba(t_stack *a, t_stack *b, int c);
int				calc_rrarrb_ba(t_stack *a, t_stack *b, int c);
int				calc_rarrb_ba(t_stack *a, t_stack *b, int c);
int				calc_rrarb_ba(t_stack *a, t_stack *b, int c);

// rotate_and_push.c
int				execute_rarb(t_stack **a, t_stack **b, int target, char id_s);
int				execute_rrarrb(t_stack **a, t_stack **b, int target, char id_s);
int				execute_rrarb(t_stack **a, t_stack **b, int target, char id_s);
int				execute_rarrb(t_stack **a, t_stack **b, int target, char id_s);

#endif