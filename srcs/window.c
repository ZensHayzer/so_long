/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:43:53 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/23 00:20:41 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	init_images_1(void *mlx, t_images *img)
{
	img->p_d = mlx_xpm_file_to_image(mlx, "assets/p_d.xpm", &img->x_size,
			&img->y_size);
	img->p_w = mlx_xpm_file_to_image(mlx, "assets/p_w.xpm", &img->x_size,
			&img->y_size);
	img->p_a = mlx_xpm_file_to_image(mlx, "assets/p_a.xpm", &img->x_size,
			&img->y_size);
	img->exit_o = mlx_xpm_file_to_image(mlx, "assets/exit_o.xpm", &img->x_size,
			&img->y_size);
	if (!img->p_d || !img->p_w || !img->p_a || !img->exit_o)
		return (0);
	return (1);
}

int	init_images(void *mlx, t_images *img)
{
	img->ground = mlx_xpm_file_to_image(mlx, "assets/ground.xpm", &img->x_size,
			&img->y_size);
	img->wall = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", &img->x_size,
			&img->y_size);
	img->item = mlx_xpm_file_to_image(mlx, "assets/item.xpm", &img->x_size,
			&img->y_size);
	img->p1 = mlx_xpm_file_to_image(mlx, "assets/player_s.xpm", &img->x_size,
			&img->y_size);
	img->p2 = mlx_xpm_file_to_image(mlx, "assets/player_s_1.xpm", &img->x_size,
			&img->y_size);
	img->p3 = mlx_xpm_file_to_image(mlx, "assets/player_s_2.xpm", &img->x_size,
			&img->y_size);
	img->p4 = mlx_xpm_file_to_image(mlx, "assets/player_s_3.xpm", &img->x_size,
			&img->y_size);
	img->exit = mlx_xpm_file_to_image(mlx, "assets/exit_c.xpm", &img->x_size,
			&img->y_size);
	img->enc = mlx_xpm_file_to_image(mlx, "assets/monster.xpm", &img->x_size,
			&img->y_size);
	if (!img->ground || !img->wall || !img->item || !img->p1 || !img->p2
		|| !img->p3 || !img->p4 || !img->exit || !img->enc
		|| !init_images_1(mlx, img))
		return (0);
	return (1);
}

void	fill_window(t_map_content *map_c, char move)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_c->tot_lines)
	{
		j = 0;
		while (j < map_c->lines_len)
		{
			fill_window_forest(map_c, move, i, j);
			j++;
		}
		i++;
	}
	return ;
}

int	window_init(t_vars *vars, t_map_content *map_c, t_images *img)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	if (!init_images(vars->mlx, img))
		return (0);
	vars->win = mlx_new_window(vars->mlx, map_c->lines_len * img->x_size,
			map_c->tot_lines * img->y_size, "So_Long");
	return (1);
}

int	window(t_map_content map_c)
{
	window_init(&map_c.vars, &map_c, &map_c.img);
	fill_window(&map_c, 's');
	mlx_loop_hook(map_c.vars.mlx, &animation_p, &map_c);
	mlx_hook(map_c.vars.win, KeyPress, KeyPressMask, &close_hook, &map_c);
	mlx_hook(map_c.vars.win, ClientMessage, LeaveWindowMask, &close_hook_cross,
		&map_c);
	mlx_loop(map_c.vars.mlx);
	return (0);
}
