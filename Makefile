# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 14:11:30 by jbrandt           #+#    #+#              #
#    Updated: 2025/01/11 14:05:39 by jbrandt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs
vpath %.c libft

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./include
FLAGS = -O3 -g3 -L -lft

LIBFT = ./libft
LIBS = /include

RM = rm -f

$(LIBMLX):
    git submodule update --init --recursive
    @cmake MLX42 -B MLX42/build && make -C MLX42/build -j4

OBJ_DIR = build

OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I.$(LIBS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a $(FLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJ_DIR)/*.o

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all