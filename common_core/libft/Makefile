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
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
SRCS        = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
              ft_strlen.c  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
              ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
              ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
              ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
              ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
              ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))
AR = ar rcs
RM = rm -f

# Static lib from object files
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compile .c files to .o files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
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
