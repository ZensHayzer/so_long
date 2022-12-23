/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:09:58 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/23 01:03:46 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"

/* ***************************/
/* 			STRUCTS			 */
/* ***************************/

typedef struct s_images
{
	void	*wall;
	void	*ground;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;
	void	*p_w;
	void	*p_a;
	void	*p_d;
	void	*item;
	void	*exit;
	void	*exit_o;
	void	*enc;
	int		x_size;
	int		y_size;
}		t_images;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct s_monster
{
	int	mon_x;
	int	mon_y;
	char	last_pos;
	struct s_monster	*next;
}		t_mon;

typedef struct s_map_content
{
	int			walls;
	int			items;
	int			exit;
	int			start;
	int			enc;
	int			i;
	int			tot_lines;
	int			lines_len;
	int			items_got;
	int			player_x;
	int			player_y;
	int			mv;
	char		last_pos;
	char		*map_name;
	char		**map;
	struct s_monster	*mons;
	t_images	img;
	t_vars	vars;
}		t_map_content;

/* ***************************/
/* 			FUNCTIONS		 */
/* ***************************/

// map_checker
int		ber_checker(char *str);
int		map_builder(t_map_content *map_content);
int		lines(t_map_content *map_content);
int		present_char(t_map_content *map_content);

// map_checker1
int		wall_checker(t_map_content *map_content);
int		pre_check_wrong_map(t_map_content *map_content);
int		access_checker(t_map_content *map_content);

// error
int		map_checker_error(int err);
int		lines_error(int err);
int		present_char_error(int err);
int		wall_checker_error(int err);
int		pre_check_wrong_map_error(char *buf, int err);

// error1
int		access_checking_error(int err, int **bool_map, int height);

// utils
void	ft_puterr(char *str);
char	*gnl_corrector(char *str);
char	*ft_calloc_so(size_t nmemb, size_t size);
int		is_in(char *str, char c);
void	fill_window_forest(t_map_content *map_c, char mv, int i, int j);

// utils1
t_mon	*ft_lstnew();
int		ft_lstaddback(t_mon **lst, t_mon *element);

// initialize
int		map_content_initializer(t_map_content *map_content);
void	access_checker_initializer(t_map_content *map_content,
			t_map_content *map_content_copy);
int		monster_init(t_map_content *map_c, t_mon **mon);

// bool_map
void	free_boolmap(int **bool_map, int height);
void	fill_boolmap(char **map, int **bool_map, int height, int width);
int		**init_boolmap(char **map, int height, int width);

// recursive_checker
int		exit_checker(char **map, int **bool_map, int y, int x);
int		collectibles_checker(t_map_content *map_content, int **bool_map, int y,
			int x);

// window
int		init_images_1(void *mlx, t_images *img);
int		init_images(void *mlx, t_images *img);
int		window_init(t_vars *vars, t_map_content *map_c, t_images *img);
int		window(t_map_content map_content);
void	fill_window(t_map_content *map_c, char move);

// hooks
int		close_hook(int keycode, t_map_content *map_c);
int		close_hook_cross(t_map_content *map_c);
int		animation_p(t_map_content *map_c);

// monster
int	monster_move_up(t_map_content *map_c, t_mon *mon);
int	monster_move(t_map_content *map_c);

// player
int		player_move(char c, t_map_content *map_c);

// ft_itoa
char	*ft_itoa(int n);

//	free
void	free_map_content(t_map_content *map_content);
void	free_closing(t_map_content *map_c, t_vars *vars);
void	close_img(t_vars *vars, t_images *img);
void	close_img_1(t_vars *vars, t_images *img);

// free1
void	free_monster_lst(t_mon *mon);
#endif
