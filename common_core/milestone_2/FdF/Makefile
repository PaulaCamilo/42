# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 13:02:14 by pbranco-          #+#    #+#              #
#    Updated: 2025/03/03 19:09:04 by ppaula-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

SRC 		= srcs/color.c \
				srcs/draw.c \
				srcs/handling.c \
				srcs/input_check.c \
				srcs/input_parsing_helpers.c \
				srcs/input_parsing_helpers2.c \
				srcs/input_parsing.c \
				srcs/main.c \
				srcs/rendering.c \
				srcs/setup.c \
				srcs/utils.c
				
OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

GNL_DIR		= ./gnl
GNL			= $(GNL_DIR)/get_next_line.a

MLX_DIR		= ./mlx
MLX			= $(MLX_DIR)/libmlx.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all:		$(GNL) $(LIBFT) $(MLX) $(NAME)

$(GNL):
				@$(MAKE) -C $(GNL_DIR)

$(MLX):
				@if [ ! -d "$(MLX_DIR)" ]; then \
					echo "Cloning MiniLibX..."; \
					git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
				fi
				@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
				@$(MAKE) -C $(LIBFT_DIR)

$(NAME): 	$(OBJS) $(LIBFT) $(MLX)	
				$(CC) $(CFLAGS) $(SRC) $(GNL) $^ $(MLX_FLAGS) -o $(NAME)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)
				@$(MAKE) fclean -C $(GNL_DIR)
				@$(MAKE) fclean -C $(LIBFT_DIR)
				@$(MAKE) clean -C $(MLX_DIR)

fclean:		clean
				$(RM) $(NAME)
				@$(MAKE) fclean -C $(GNL_DIR)
				@$(MAKE) fclean -C $(LIBFT_DIR)
				@$(MAKE) clean -C $(MLX_DIR)
				@if [ -d "$(MLX_DIR)" ]; then \
					echo "Removing MiniLibX..."; \
					rm -rf $(MLX_DIR); \
				fi

re:			fclean all

.PHONY:		all clean fclean re
