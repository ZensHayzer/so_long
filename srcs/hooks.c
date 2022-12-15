/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:14:03 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/15 15:57:19 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	close_hook(int keycode, t_map_content *map_c)
{
	if (keycode == XK_Escape)
	{
		close_img(&map_c->vars, &map_c->img);
		mlx_destroy_window(map_c->vars.mlx, map_c->vars.win);
		mlx_destroy_display(map_c->vars.mlx);
		free_closing(map_c, &map_c->vars);
	}
	else if (is_in("wasd", keycode))
	{
		if (player_move(keycode, map_c))
			fill_window(map_c, map_c->vars.mlx, map_c->vars.win, map_c->img);
	}
	return (keycode);
}

int	close_hook_cross(t_map_content *map_c)
{
	close_img(&map_c->vars, &map_c->img);
	mlx_destroy_window(map_c->vars.mlx, map_c->vars.win);
	mlx_destroy_display(map_c->vars.mlx);
	free_closing(map_c, &map_c->vars);
	return (0);
}
