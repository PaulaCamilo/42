# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:39:09 by ppaula-d          #+#    #+#              #
#    Updated: 2025/01/27 17:07:37 by ppaula-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------=---------------------------------------#
#			        			   VARIABLES				   			       #
#--------------------------------------=---------------------------------------#

NAME 	= push_swap
CC 		= cc
RM 		= rm -f
FLAGS 	= -Wall -Werror -Wextra -g
SRC    	= push_swap.c \
			ft_utils.c \
			ft_utils_2.c \
			algorithm.c \
			list_utils.c \
			stack_utils.c \
			free_utils.c \
			sort_utils.c \
			operations_stack_a.c \
			operations_stack_b.c \
			operations_both_stacks.c \
			index_utils.c \
			rotation_type.c \
			costs_ab.c \
			costs_ba.c \
			rotate_and_push.c \
			
OBJ 	= $(SRC:.c=.o)

#--------------------------------------=---------------------------------------#
#			        			     RULES      			    		       #
#--------------------------------------=---------------------------------------#

%.o: %.cc
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all : $(NAME)	

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re