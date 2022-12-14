/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:14:03 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/13 22:43:03 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	close_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		close_img(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
	}
	// else if (is_in("wasd", keycode))
	// 	player_move();
	return (keycode);
}
