# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:39:09 by ppaula-d          #+#    #+#              #
#    Updated: 2025/01/20 11:49:36 by ppaula-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------=---------------------------------------#
#			        			   VARIABLES				   			       #
#--------------------------------------=---------------------------------------#

NAME 	= push_swap
CC 		= cc
RM 		= rm -f
FLAGS 	= -Wall -Werror -Wextra -g
INCLUDE	= -I include/
SRC    	= srcs/push_swap.c \
			srcs/ft_utils.c \
			srcs/ft_utils_2.c \
			srcs/algorithm.c \
			srcs/list_utils.c \
			srcs/stack_utils.c \
			srcs/free_utils.c \
			srcs/sort_utils.c \
			srcs/operations_stack_a.c \
			srcs/operations_stack_b.c \
			srcs/operations_both_stacks.c \
			srcs/index_utils.c \
			srcs/rotation_type.c \
			srcs/costs_ab.c \
			srcs/costs_ba.c \
			srcs/rotate_and_push.c \
			
OBJ 	= $(SRC:.c=.o)

#--------------------------------------=---------------------------------------#
#			        			     RULES      			    		       #
#--------------------------------------=---------------------------------------#

%.o: %.cc
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all : $(NAME)	

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re