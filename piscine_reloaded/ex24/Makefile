# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:39:09 by ppaula-d          #+#    #+#              #
#    Updated: 2024/10/16 12:39:10 by ppaula-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
SRC_DIR = srcs
INC_DIR = includes
SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM = rm -f

# Static lib from object files
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compile .c files to .o files
%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build the library (default target)
all: $(NAME)

#Remove object files
clean:
	$(RM) $(OBJS)

# Remove object files and static library
fclean: clean
	$(RM) $(NAME)

# Recompile the entire library, cleaning everything and then building the library
re: fclean all
