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
SRC_DIR = srcs
INC_DIR = includes
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
AR = ar rcs
RM = rm -f

# Static lib from object files
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compile .c files to .o files
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build the library (default target)
all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

#Remove object files
clean:
	$(RM) $(OBJS)

# Remove object files and static library
fclean: clean
	$(RM) $(NAME)

# Recompile the entire library, cleaning everything and then building the library
re: fclean all

.PHONY: all clean fclean re