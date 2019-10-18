# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 16:40:35 by julesqvgn         #+#    #+#              #
#    Updated: 2019/10/09 18:34:08 by roduquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = lem-in

NAMEVIZU = lem-vizu

FLAGS = -Wall -Wextra -Werror

OPT_FLAGS =

LIBFT = -L ./libft/ -I ./libft/include -lft

LIBFTOBJ = -I ./libft/include

SDL = -L ~/.brew/lib/ -I ~/.brew/include/SDL2 `sdl2-config --cflags --libs`

SDLOBJ = -I ~/.brew/include/SDL2

INCLUDE = -I ./includes

SRC_PATH = ./srcs
INC_PATH = ./includes
OBJ_PATH = ./obj

SRCS_NAME =	parsing/parser.c						\
			parsing/check_and_fill_tree.c			\
			parsing/check_part2.c					\
			parsing/check_node_format.c				\
			parsing/add_link_to_list.c				\
			parsing/add_room_to_list.c				\
			parsing/translate_list_to_string.c		\
			parsing/convert_to_usefull.c			\
			lemin.c									\
			leave.c									\
			algorithm/breadth_first_search.c		\
			algorithm/edmonds_karp.c				\
			algorithm/flow_optimizer.c				\
			algorithm/bfs_helper.c					\
			algorithm/create_new_elem_for_queue.c	\
			display.c								\
			print_lem.c

VIZ_NAME =	vizu/parse.c \
			vizu/list.c \
			vizu/parse_utils.c \
			vizu/visual.c \
			vizu/visual2.c \
			vizu/parse_path.c

OBJ_NAME = $(SRCS_NAME:.c=.o)

OVIZ_NAME = $(VIZ_NAME:.c=.o)

INC_NAME = lemin.h

INCV_NAME = leminvizu.h

SRCS = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
VIZ = $(addprefix $(SRC_PATH)/, $(VIZ_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
INCV = $(addprefix $(INC_PATH)/, $(INCV_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OVIZ = $(addprefix $(OBJ_PATH)/,$(OVIZ_NAME))

all: logo libft $(NAME) $(NAMEVIZU)

$(NAME): $(INC) $(OBJ)
	@$(CC) $(FLAGS) $(OPT_FLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[38;2;0;255;255mLem-in\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"
	@echo "\033[38;2;0;255;255mLem-in\t\033[38;2;255;0;0m$(NAME)\t\t\033[0;32m[OK]\033[0m"

$(NAMEVIZU): $(INCV) $(OVIZ)
	@$(CC) $(FLAGS) $(OPT_FLAGS) $(INCLUDE) $(OVIZ) $(LIBFT) $(SDL) -o $(NAMEVIZU)
	@echo "\033[38;2;0;255;255mLem-in\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"
	@echo "\033[38;2;0;255;255mLem-in\t\033[38;2;255;0;0m$(NAMEVIZU)\t\033[0;32m[OK]\033[0m"

libft:
	@$(MAKE) -C Libft/

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@mkdir -p $(OBJ_PATH)/parsing 2> /dev/null || true
	@mkdir -p $(OBJ_PATH)/algorithm 2> /dev/null || true
	@mkdir -p $(OBJ_PATH)/vizu 2> /dev/null || true
	@echo "\033[38;2;0;255;0m[cc]\033[0m: $< -> $@"
	@printf "\e[1A"
	@$(CC) $(FLAGS) $(OPT_FLAGS) $(INCLUDE) $(LIBFTOBJ) $(SDLOBJ) -c $< -o $@
	@printf "\e[0K"

clean:
	@rm -rf $(OBJ) $(OVIZ)
	@echo "\033[38;2;0;255;255mLem-in\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -rf ./obj $(NAME) $(NAMEVIZU)
	@echo "\033[38;2;0;255;255mLem-in\t\033[1;33mCleaning exe\t\033[0;32m[OK]\033[0m"

logo:
	@echo ""
	@echo   "\033[38;2;0;0;255m __                              _           "
	@echo  "\033[38;2;38;0;255m[  |                            (_)          "
	@echo  "\033[38;2;76;0;255m | | .---.  _ .--..--.  ______  __   _ .--.  "
	@echo "\033[38;2;114;0;255m | |/ /__\\[ \`.-. .-. ||______|[  | [ \`.-. | "
	@echo "\033[38;2;152;0;255m | || \__., | | | | | |         | |  | | | | "
	@echo "\033[38;2;191;0;255m[___]'.__.'[___||__||__]       [___][___||__]"
	@echo "\033[0m"

re : fclean all

.PHONY : all clean fclean re libft logo
