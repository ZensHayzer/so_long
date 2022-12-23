/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:14:03 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/23 00:21:56 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	close_hook(int keycode, t_map_content *map_c)
{
	char	*mv;

	mv = NULL;
	if (keycode == XK_Escape)
		free_closing(map_c, &map_c->vars);
	else if (is_in("wasd", keycode))
	{
		if (player_move(keycode, map_c))
		{
			monster_move(map_c);
			mv = ft_itoa(map_c->mv);
			fill_window(map_c, keycode);
			mlx_string_put(map_c->vars.mlx, map_c->vars.win, 20, 20,
				0xFEFEFF, mv);
			if (mv)
				free(mv);
		}
	}
	return (keycode);
}

int	close_hook_cross(t_map_content *map_c)
{
	free_closing(map_c, &map_c->vars);
	return (0);
}

int	animation_p(t_map_content *map_c)
{
	if (map_c->i == 10000)
		mlx_put_image_to_window(map_c->vars.mlx, map_c->vars.win, map_c->img.p2,
			map_c->player_x * map_c->img.x_size,
			map_c->player_y * map_c->img.y_size);
	if (map_c->i == 20000)
		mlx_put_image_to_window(map_c->vars.mlx, map_c->vars.win, map_c->img.p3,
			map_c->player_x * map_c->img.x_size,
			map_c->player_y * map_c->img.y_size);
	if (map_c->i == 30000)
		mlx_put_image_to_window(map_c->vars.mlx, map_c->vars.win, map_c->img.p4,
			map_c->player_x * map_c->img.x_size,
			map_c->player_y * map_c->img.y_size);
	if (map_c->i == 40000)
		mlx_put_image_to_window(map_c->vars.mlx, map_c->vars.win, map_c->img.p1,
			map_c->player_x * map_c->img.x_size,
			map_c->player_y * map_c->img.y_size);
	map_c->i++;
	if (map_c->i >= 50000)
		map_c->i = 0;
	return (0);
}
