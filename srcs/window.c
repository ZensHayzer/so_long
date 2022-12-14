/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:43:53 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/13 22:24:09 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	init_images(void *mlx, t_images *images)
{
	images->ground = mlx_xpm_file_to_image(mlx, "assets/ground.xpm", &images->x_size,
										&images->y_size);
	images->wall = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", &images->x_size,
										&images->y_size);
	images->item = mlx_xpm_file_to_image(mlx, "assets/item.xpm", &images->x_size,
										&images->y_size);
	images->player = mlx_xpm_file_to_image(mlx, "assets/player.xpm", &images->x_size,
										&images->y_size);
	images->exit = mlx_xpm_file_to_image(mlx, "assets/exit.xpm", &images->x_size,
										&images->y_size);
	if (!images->ground || !images->wall || !images->item || !images->player
		|| !images->exit)
		return (0); //TODO ERROR LOADING IMAGE
	return (1);
}

void	close_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->exit);
	mlx_destroy_image(vars->mlx, vars->img->item);
	mlx_destroy_image(vars->mlx, vars->img->player);
	mlx_destroy_image(vars->mlx, vars->img->ground);
	mlx_destroy_image(vars->mlx, vars->img->wall);
}

void	fill_window(t_map_content *map_content, void *mlx, void *win, t_images img)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_content->tot_lines)
	{
		j = 0;
		while (j < map_content->lines_len)
		{
			if (map_content->map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img.wall, j * img.x_size, i * img.y_size);
			if (map_content->map[i][j] == '0')
				mlx_put_image_to_window(mlx, win, img.ground, j * img.x_size, i * img.y_size);
			if (map_content->map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, img.player, j * img.x_size, i * img.y_size);
			if (map_content->map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, img.item, j * img.x_size, i * img.y_size);
			if (map_content->map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, img.exit, j * img.x_size, i * img.y_size);
			j++;
		}
		i++;
	}
	return ;
}

int	window_init(t_vars *vars, t_map_content *map_content, t_images *img)
{
	vars->mlx = mlx_init();
	if (!init_images(vars->mlx, img))
		return (0);
	vars->win = mlx_new_window(vars->mlx, map_content->lines_len * img->x_size,
						map_content->tot_lines * img->y_size, "So_Long wlh");
	return (1);
}

int window(t_map_content *map_content)
{
	t_vars		vars;
	t_images	images;

	vars.img = &images;
	window_init(&vars, map_content, &images);
	fill_window(map_content, vars.mlx, vars.win, images);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &close_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
