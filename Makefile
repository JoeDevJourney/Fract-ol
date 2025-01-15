# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 14:11:30 by jbrandt           #+#    #+#              #
#    Updated: 2025/01/15 03:20:58 by jbrandt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = srcs 

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g


HEADERS = -I. -I $(LIBMLX)/include

SRCS = fractol.c utils.c utils2.c color.c events.c initia.c render.c

SRCOBJ = $(SRCS:%.c=%.o) 

LIBMLX = ./lib/MLX42

LIBFT = ./libft

LIB = $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

RM = rm -f

all: gitclone libmlx libft $(NAME)

gitclone:	
	@if [ ! -d "$(LIBMLX)" ]; then \
		echo "Cloning MLX42..."; \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi

libmlx: $(LIBMLX)/build/libmlx42.a

$(LIBMLX)/build/libmlx42.a: $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build

libft: 
	@make -C $(LIBFT)

$(NAME):	$(SRCOBJ) 
	$(CC) $(CFLAGS) $(SRCOBJ) $(LIB) $(HEADERS) -o $(NAME)
	@echo "Executable $(NAME) has been created."

%.o:	%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

clean:	
	$(RM) $(SRCOBJ) 
	make clean -C $(LIBFT)
	@echo "Object files have been deleted."

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)
	@echo "Library has been deleted."

re: fclean all 

.PHONY: all clean fclean re libft libmlx gitclone