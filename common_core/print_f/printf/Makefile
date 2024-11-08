# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:39:09 by ppaula-d          #+#    #+#              #
#    Updated: 2024/11/08 15:39:02 by ppaula-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------=---------------------------------------#
#			        			   VARIABLES				   			       #
#--------------------------------------=---------------------------------------#

NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRC_DIR = printf
SRCS    = ft_check_format.c	ft_print_char.c	ft_print_dec_int.c \
		ft_print_hexa.c ft_print_pointer.c ft_print_string.c \
		ft_print_un_dec.c ft_printf_utils.c ft_printf.c
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
