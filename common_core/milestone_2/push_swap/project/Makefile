# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:39:09 by ppaula-d          #+#    #+#              #
#    Updated: 2025/02/11 23:20:49 by ppaula-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------=---------------------------------------#
#			        			   VARIABLES				   			       #
#--------------------------------------=---------------------------------------#

NAME 		= push_swap
CC 			= cc
RM 			= rm -f
FLAGS 		= -Wall -Werror -Wextra -g 
INCLUDE 	= -I ./include
LIBFT_DIR 	= libft
LIBFT 		= $(LIBFT_DIR)/libft.a
SRC    		= srcs/costs_ab.c \
				srcs/costs_ba.c \
				srcs/index_utils.c \
				srcs/list_utils.c \
				srcs/operations_both_stacks.c \
				srcs/operations_stack_a.c \
				srcs/operations_stack_b.c \
				srcs/parsing.c \
				srcs/push_swap.c \
				srcs/rotate_and_push.c \
				srcs/rotation_type.c \
				srcs/sort_utils.c \
				srcs/stack_utils.c \
			
OBJ 	= $(SRC:.c=.o)

#--------------------------------------=---------------------------------------#
#			        			     RULES      			    		       #
#--------------------------------------=---------------------------------------#

all : $(LIBFT) $(NAME)

$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ) 
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY:		all clean fclean re