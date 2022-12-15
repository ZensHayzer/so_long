/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:43:53 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/15 15:55:35 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	init_images(void *mlx, t_images *img)
{
	img->ground = mlx_xpm_file_to_image(mlx, "assets/ground.xpm", &img->x_size,
										&img->y_size);
	img->wall = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", &img->x_size,
										&img->y_size);
	img->item = mlx_xpm_file_to_image(mlx, "assets/item.xpm", &img->x_size,
										&img->y_size);
	img->player = mlx_xpm_file_to_image(mlx, "assets/player.xpm", &img->x_size,
										&img->y_size);
	img->exit = mlx_xpm_file_to_image(mlx, "assets/exit.xpm", &img->x_size,
										&img->y_size);
	if (!img->ground || !img->wall || !img->item || !img->player || !img->exit)
		return (0); //TODO ERROR LOADING IMAGE
	return (1);
}

void	close_img(t_vars *vars, t_images *img)
{
	if (img->exit)
		mlx_destroy_image(vars->mlx, img->exit);
	if (img->item)
		mlx_destroy_image(vars->mlx, img->item);
	if (img->player)
		mlx_destroy_image(vars->mlx, img->player);
	if (img->ground)
		mlx_destroy_image(vars->mlx, img->ground);
	if (img->wall)
		mlx_destroy_image(vars->mlx, img->wall);
}

void	fill_window(t_map_content *map_c, void *mlx, void *win, t_images img)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_c->tot_lines)
	{
		j = 0;
		while (j < map_c->lines_len)
		{
			if (map_c->map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img.wall, j * img.x_size, i * img.y_size);
			if (map_c->map[i][j] == '0')
				mlx_put_image_to_window(mlx, win, img.ground, j * img.x_size, i * img.y_size);
			if (map_c->map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, img.player, j * img.x_size, i * img.y_size);
			if (map_c->map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, img.item, j * img.x_size, i * img.y_size);
			if (map_c->map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, img.exit, j * img.x_size, i * img.y_size);
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

int window(t_map_content map_c)
{
	window_init(&map_c.vars, &map_c, &map_c.img);
	fill_window(&map_c, map_c.vars.mlx, map_c.vars.win, map_c.img);
	mlx_hook(map_c.vars.win, KeyPress, KeyPressMask, &close_hook, &map_c);
	mlx_hook(map_c.vars.win, ClientMessage, LeaveWindowMask, &close_hook_cross, &map_c);
	mlx_loop(map_c.vars.mlx);
	return (0);
}
