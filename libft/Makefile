# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 16:55:06 by julesqvgn         #+#    #+#              #
#    Updated: 2019/10/09 13:11:38 by roduquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

INCLUDE = -I./include/

SRCS_PATH = ./srcs
INC_PATH = ./include
OBJ_PATH = ./obj

SRCS_NAME =	./ft_atoi.c \
			./ft_strtol.c \
			./ft_isalnum.c \
			./ft_isalpha.c \
			./ft_isascii.c \
			./ft_isdigit.c \
			./ft_isprint.c \
			./ft_strlen.c \
			./ft_tolower.c \
			./ft_toupper.c \
			./ft_strcmp.c \
			./ft_strncmp.c \
			./ft_strcpy.c \
			./ft_strncpy.c \
			./ft_strcat.c \
			./ft_strncat.c \
			./ft_strlcat.c \
			./ft_strstr.c \
			./ft_strnstr.c \
			./ft_bzero.c \
			./ft_memset.c \
			./ft_memcpy.c \
			./ft_memccpy.c \
			./ft_memchr.c \
			./ft_strchr.c \
			./ft_strrchr.c \
			./ft_memcmp.c \
			./ft_memalloc.c \
			./ft_memdel.c \
			./ft_strnew.c \
			./ft_strdel.c \
			./ft_strclr.c \
			./ft_striter.c \
			./ft_striteri.c \
			./ft_strmap.c \
			./ft_strmapi.c \
			./ft_strequ.c \
			./ft_strnequ.c \
			./ft_strsub.c \
			./ft_strjoin.c \
			./ft_strtrim.c \
			./ft_strsplit.c \
			./ft_itoa.c \
			./ft_putchar.c \
			./ft_putstr.c \
			./ft_putendl.c \
			./ft_putnbr.c \
			./ft_putchar_fd.c \
			./ft_putstr_fd.c \
			./ft_putendl_fd.c \
			./ft_putnbr_fd.c \
			./ft_lstnew.c \
			./ft_lstdelone.c \
			./ft_lstdel.c \
			./ft_lstadd.c \
			./ft_lstiter.c \
			./ft_lstmap.c \
			./ft_isspace.c \
			./ft_iswhitespace.c \
			./ft_memrchr.c \
			./ft_strlendl.c \
			./queue_forward.c \
			./ft_lstadd_back.c \
			./queue_new.c \
			./queue_add.c\
			./ft_realloc.c \
			./ft_strrev.c \
			./ft_swapchar.c \
			./ft_strdup.c \
			./ft_memmove.c \
			./btree_apply_infix.c \
			./btree_apply_prefix.c \
			./btree_apply_suffix.c \
			./btree_create_node.c \
			./btree_insert_data.c \
			./btree_search_item.c \
			./btree_leaf_count.c \
			./btree_level_count.c \
			./cocktail_sort_int.c \
			./quick_sort_int.c \
			./quick_sort_string.c \
			./cocktail_sort_string.c \
			./free_ptr.c \
			./infinity_add.c \
			./infinity_mult.c \
			./get_next_line.c \
			./ft_strndup.c

INC_NAME = libft.h
OBJ_NAME = $(SRCS_NAME:.c=.o)

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar sucr $(NAME) $(OBJ)
	@echo "\033[1;34mlibft\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[38;2;0;255;0m[cc]\033[0m: $< -> $@"
	@printf "\e[1A"
	@$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<
	@printf "\e[0K"

clean:
	@rm -rf $(OBJ)
	@echo "\033[1;34mlibft\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean:
	@rm -rf ./obj $(NAME)
	@echo "\033[1;34mlibft\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all
