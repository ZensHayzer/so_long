/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:09:58 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/14 18:42:59 by ajeanne          ###   ########.fr       */
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

typedef	struct s_map_content
{
	int		walls;
	int		items;
	int		exit;
	int		start;
	int		tot_lines;
	int		lines_len;
	int		items_got;
	int		player_x;
	int		player_y;
	char	last_pos;
	char	*map_name;
	char	**map;
}		t_map_content;

typedef	struct s_images
{
	void	*wall;
	void	*ground;
	void	*player;
	void	*item;
	void	*exit;
	int		x_size;
	int		y_size;
}		t_images;

typedef	struct s_vars
{
	void	*mlx;
	void	*win;
	t_images		*img;
}		t_vars;


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

// initialize
int		map_content_initializer(t_map_content *map_content);
void	access_checker_initializer(t_map_content *map_content,
			t_map_content *map_content_copy);

// bool_map
void	free_boolmap(int **bool_map, int height);
void	fill_boolmap(char **map, int **bool_map, int height, int width);
int		**init_boolmap(char **map, int height, int width);

// recursive_checker
int		exit_checker(char **map, int **bool_map, int y, int x);
int		collectibles_checker(t_map_content *map_content, int **bool_map, int y, int x);

// window
int 	window(t_map_content *map_content);
void	close_img(t_vars *vars);

// hooks
int		close_hook(int keycode, t_vars *vars);

//	free
void	free_map_content(t_map_content *map_content);
#endif
