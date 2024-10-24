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

LIB			= libft

SRCS        = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
              ft_strlen.c  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
              ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
              ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
              ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
              ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
              ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

COMPILER	= cc

FLAGS		= -Wall -Wextra -Werror

OUTN		= $(LIB).a

CFILES		= $(SRCS:%.c)

OFILES		= $(SRCS:%.o)

NAME		= $(OUTN)

$(NAME):
			$(COMPILER) $(FLAGS) -c $(CFILES) -I./
			ar -rcs $(OUTN) $(OFILES)

all: 		$(NAME)

clean:
			rm -f $(NAME) $(OFILES)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, re