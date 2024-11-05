# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:39:09 by ppaula-d          #+#    #+#              #
#    Updated: 2024/11/04 15:26:18 by ppaula-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------=---------------------------------------#
#			        			   VARIABLES				   			       #
#--------------------------------------=---------------------------------------#

NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRC_DIR = printf
SRCS    = ft_printc.c \
		ft_printf.c \
		ft_printstr.c \
		ft_putchar_fd.c	\
		ft_putstr_fd.c \
		ft_strlen.c
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
