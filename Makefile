# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 19:47:23 by sadolph           #+#    #+#              #
#    Updated: 2020/10/13 17:21:05 by sadolph          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Directories
SRC_DIR := ./src/
OBJ_DIR := ./obj/
LIBFT_DIR := ./libft/

INC_DIR := ./includes/
INC_PRINTF := ft_printf.h
LINK_INC := $(addprefix -I, $(INC_DIR) $(LIBFT_DIR)includes/)

# Sources
LIBFT_NAME := libft.a
NAME := libftprintf.a
SRC :=			\
ft_printf.c		\
print_arg.c		\
print_c.c		\
print_di.c		\
print_p.c		\
print_perc.c	\
print_s.c		\
print_u.c		\
print_x.c		\
if_modifier.c	\
utils.c

# Objects
OBJ := ${SRC:.c=.o}
O_WITH_DIR := $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

# Add printf's object files to the libftprintf.a (renamed libft.a)
# Now, it's complete collection of all necessary functions into libftprintf.a
$(NAME): $(O_WITH_DIR) $(LIBFT_NAME)
	ar rc $@ $(O_WITH_DIR)
	ranlib $@
	@echo "\033[32m$@ successfully created\033[0m" ✅

# Dependencies that allow recompile obj files from only changed source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)$(INC_PRINTF)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LINK_INC) -c $< -o $@

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT_NAME) ./
	mv $(LIBFT_NAME) $(NAME)

# Standard rules separated for ft_printf & libft:
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
re: fclean all

.PHONY: all clean fclean re add_libft
