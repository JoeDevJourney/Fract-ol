# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 17:25:46 by jbrandt           #+#    #+#              #
#    Updated: 2024/12/02 12:36:48 by jbrandt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
INCLUDE_DIR = include

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_strncmp.c ft_memchr.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
ft_putendl_fd.c ft_split.c ft_memcmp.c \
ft_strmapi.c ft_striteri.c \
$(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_putstrprint.c \
$(FT_PRINTF_DIR)/ft_printp.c $(FT_PRINTF_DIR)/ft_printid.c $(FT_PRINTF_DIR)/ft_printu.c \
$(FT_PRINTF_DIR)/ft_printhex.c \
$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

SRC_BONUS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c \
ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c \

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

bonus: $(OBJ) $(OBJ_BONUS) 
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I $(FT_PRINTF_DIR)/include -I $(GNL_DIR)/include -c $< -o $@
	
clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
