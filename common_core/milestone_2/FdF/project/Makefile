# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:39:09 by ppaula-d          #+#    #+#              #
#    Updated: 2025/02/05 15:35:48 by ppaula-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------=---------------------------------------#
#			        			     NAMES	 				   			       #
#--------------------------------------=---------------------------------------#

UNAME			= $(shell uname)
NAME 			= fdf

### Message vars
_NAME			= [$(WHI)FdF$(B)]
_SUCESS			= [$(GRN)SUCCESS$(D)]

#--------------------------------------=---------------------------------------#
#			        			     PATHS	 				   			       #
#--------------------------------------=---------------------------------------#

SRCS  			= srcs
BONUS	 		= bonus
INCLUDE			= inc
LIBS			= lib
BUILD			= .build
MLX				= $(LIBS)/mlx


### Files source
FILES 			= main.c
FILES 			+= parsing.c

### Paths
SRCS_PATH		= $(addprefix $(SRCS)/, $(FILES))
OBJS 			= $(SRCS_PATH:$(SRCS)/%.c=$(BUILD)/%.o)

### Library archives
MLX_ARC			= $(LIBS)/libmlx.a

#--------------------------------------=---------------------------------------#
#			        		   COMPILER & FLAGS				   			       #
#--------------------------------------=---------------------------------------#

CC 				= cc
CFLAGS 			= -Wall -Werror -Wextra
DFLAGS			= -g
INC				= -I $(INCLUDE)

ifeq ($(shell uname), Linux)
	MLXFLAGS		+= -lXext -lX11 -Ilmlx -lbsd -no-pie -lm
else
	MLXFLAGS		+= -lXext -lX11 -framework OpenGL -framework AppKit
endif

#--------------------------------------=---------------------------------------#
#			        		   	   COMMANDS				   			       	   #
#--------------------------------------=---------------------------------------#

RM 		= rm -f
AR 		= ar rcs
MKDIR_P	= mkdir -p

#--------------------------------------=---------------------------------------#
#			        			     RULES      			    		       #
#--------------------------------------=---------------------------------------#

# %.o: %.cc
# 	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(BUILD) $(NAME)

$(NAME): $(MLX_ARC) $(BUILD) $(OBJS)
	@echo 

-include $(BUILD)/%.d

$(BUILD)/%.o: $(SRCS)/%.cat
	@echo -n "$(RED)█$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) -MMD -MP -c $< -o $@

$(BUILD):
	$(MKDIR_P) $(BUILD)
	@echo "$(YEL)Creating $(WHI)$(BUILD)$(YEL) folder:$(D) $(_SUCESS)"	

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re

#--------------------------------------=---------------------------------------#
#			        			     UTILS      			    		       #
#--------------------------------------=---------------------------------------#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
