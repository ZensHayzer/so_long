# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 22:58:35 by ajeanne           #+#    #+#              #
#    Updated: 2023/01/23 16:13:49 by ajeanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				so_long

NAME_BONUS =		so_long_bonus

CC =				clang

CFLAGS =			-Wall -Werror -Wextra -g3

LIB_MLX =			lib/minilibx-linux

SRCS_LOC =			srcs/
SRCS_GNL =			srcs/GNL/

SRCS_LOC_BONUS =	bonus/srcs/
SRCS_GNL_BONUS =	bonus/srcs/GNL/

SRCS =		$(SRCS_LOC)main.c					\
			$(SRCS_LOC)utils.c					\
			$(SRCS_LOC)utils1.c					\
			$(SRCS_LOC)map_checker.c			\
			$(SRCS_LOC)map_checker1.c			\
			$(SRCS_LOC)error.c					\
			$(SRCS_LOC)error1.c					\
			$(SRCS_LOC)initialize.c				\
			$(SRCS_LOC)initialize1.c			\
			$(SRCS_LOC)bool_map.c				\
			$(SRCS_LOC)recursive_checker.c		\
			$(SRCS_LOC)player.c					\
			$(SRCS_LOC)ft_itoa.c				\
			$(SRCS_LOC)free.c					\
			$(SRCS_LOC)window.c					\
			$(SRCS_LOC)hooks.c					\
			$(SRCS_GNL)get_next_line.c			\
			$(SRCS_GNL)get_next_line_utils.c

SRCS_BONUS =	$(SRCS_LOC_BONUS)main.c					\
				$(SRCS_LOC_BONUS)utils.c				\
				$(SRCS_LOC_BONUS)utils1.c				\
				$(SRCS_LOC_BONUS)map_checker.c			\
				$(SRCS_LOC_BONUS)map_checker1.c			\
				$(SRCS_LOC_BONUS)error.c				\
				$(SRCS_LOC_BONUS)error1.c				\
				$(SRCS_LOC_BONUS)initialize.c			\
				$(SRCS_LOC_BONUS)initialize1.c			\
				$(SRCS_LOC_BONUS)bool_map.c				\
				$(SRCS_LOC_BONUS)recursive_checker.c	\
				$(SRCS_LOC_BONUS)player.c				\
				$(SRCS_LOC_BONUS)monster.c				\
				$(SRCS_LOC_BONUS)ft_itoa.c				\
				$(SRCS_LOC_BONUS)free.c					\
				$(SRCS_LOC_BONUS)free1.c				\
				$(SRCS_LOC_BONUS)window.c				\
				$(SRCS_LOC_BONUS)hooks.c				\
				$(SRCS_GNL_BONUS)get_next_line.c		\
				$(SRCS_GNL_BONUS)get_next_line_utils.c

OBJS =			$(SRCS:.c=.o)

OBJS_BONUS =	$(SRCS_BONUS:.c=.o)

MLX =		-L$(LIB_MLX) -lmlx_Linux -L/usr/lib -I$(LIB_MLX) -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -I/usr/includes -I$(LIB_MLX) -Imlx_linux -c $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_MLX)
	$(CC) $(CFLAGS) -I$(LIB_MLX) $(OBJS) $(MLX) -o $(NAME)

.PHONY: bonus
bonus: $(NAME_BONUS)

$(NAME_BONUS):  $(OBJS_BONUS)
	@make -C $(LIB_MLX)
	$(CC) $(CFLAGS) -I$(LIB_MLX) $(OBJS_BONUS) $(MLX) -o $(NAME_BONUS)

.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

.PHONY: re
re: fclean $(NAME)
