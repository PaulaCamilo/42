# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:39:09 by ppaula-d          #+#    #+#              #
#    Updated: 2024/12/27 10:49:08 by ppaula-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------=---------------------------------------#
#			        			   VARIABLES				   			       #
#--------------------------------------=---------------------------------------#

NAME    = push_swap.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRC_DIR = push_swap
SRCS    = 
OBJS    = $(SRCS:.c=.o)
AR      = ar rcs
RM      = rm -f

#--------------------------------------=---------------------------------------#
#			        			     RULES      			    		       #
#--------------------------------------=---------------------------------------#

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:    $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
