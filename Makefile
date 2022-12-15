# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 22:58:35 by ajeanne           #+#    #+#              #
#    Updated: 2022/12/14 20:30:08 by ajeanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		so_long

CC =		clang

CFLAGS =	-Wall -Werror -Wextra -g

LIB_MLX =	lib/minilibx-linux

SRCS_LOC =	srcs/
SRCS_GNL = srcs/GNL/

SRCS =		$(SRCS_LOC)main.c					\
			$(SRCS_LOC)utils.c					\
			$(SRCS_LOC)map_checker.c			\
			$(SRCS_LOC)map_checker1.c			\
			$(SRCS_LOC)error.c					\
			$(SRCS_LOC)error1.c					\
			$(SRCS_LOC)initialize.c				\
			$(SRCS_LOC)bool_map.c				\
			$(SRCS_LOC)recursive_checker.c		\
			$(SRCS_LOC)player.c					\
			$(SRCS_LOC)free.c					\
			$(SRCS_LOC)window.c					\
			$(SRCS_LOC)hooks.c					\
			$(SRCS_GNL)get_next_line.c			\
			$(SRCS_GNL)get_next_line_utils.c

OBJS =		$(SRCS:.c=.o)

MLX =		-L$(LIB_MLX) -lmlx_Linux -L/usr/lib -I$(LIB_MLX) -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -I/usr/includes -I$(LIB_MLX) -Imlx_linux -O3 -c $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_MLX)
	$(CC) $(CFLAGS) -I$(LIB_MLX) $(OBJS) $(MLX) -o $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean $(NAME)
