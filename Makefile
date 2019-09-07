# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grudler <grudler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 19:35:02 by grudler           #+#    #+#              #
#    Updated: 2019/09/07 19:08:24 by grudler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								Colors										   #
################################################################################

RED= \033[31m
WHITE= \033[0m
GREEN= \033[32m
CYAN= \033[36m
BLUE= \033[34m
YELLOW= \033[33m
MAGENTA= \033[35m

################################################################################
#								Macros										   #
################################################################################
NAME= fractol
CC= gcc
CFLAGS= -Wall -Wextra -Werror
FRAMEWORK=  -O2 -framework OpenGL -framework AppKit
SRC_DIR= src/
SRC= main.c\
	 mandelbrot.c\
	 julia.c\
	 burningship.c\
	 color.c\
	 grad_color.c\
	 key_handler.c\
	 mouse_handler.c\
	 leg_background.c \
	 legend.c \
	 multithread.c \
	 burningjulia.c \
	 utils.c \
	 init_var.c
SRCS= $(addprefix $(SRC_DIR),$(SRC))
OBJ_DIR= obj/
OBJ= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
LIB= -L /Users/grudler/Downloads/minilibx_macos/ -lmlx\
	 -L libft -lft

###############################################################################
#								Rules										  #
###############################################################################

all: $(NAME)

$(NAME): $(OBJ) Makefile
	@ echo "$(BLUE)Creating libft$(WHITE)"
	@ make -C libft
	@ echo "$(GREEN)Libft created$(WHITE)"
	@ echo "$(YELLOW)Creating $@ executable$(WHITE)"
	@ $(CC) -o $@ $(CFLAGS) $(OBJ) $(LIB) $(FRAMEWORK)
	@echo "$(GREEN)$@ executable created$(WHITE)"

obj:
	@mkdir obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c |obj
	@ $(CC) -o $@ -c $< $(CFLAGS)
	@ echo "$(GREEN)[✔]$(WHITE)$@"

clean:
	@ echo "$(YELLOW)Deleting objects$(WHITE)"
	@ for i in $(OBJ); do \
		echo "$(RED)-Deleting $$i$(WHITE)"; \
	done;
	@ echo "$(GREEN)Objects deleted$(WHITE)"
	@ rm -rf $(OBJ)

fclean: clean
	@ echo "$(BLUE)Cleaning libft$(WHITE)"
	@ make -C libft fclean
	@ echo "$(YELLOW)Deleting obj directory$(WHITE)"
	@ rm -rf obj
	@ echo "$(GREEN)Obj directory deleted$(WHITE)"
	@ echo "$(GREEN)Executable deleted$(WHITE)"
	@ rm -rf $(NAME)

re: fclean all
