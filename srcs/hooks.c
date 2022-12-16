/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:14:03 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/16 19:19:08 by ajeanne          ###   ########.fr       */
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
			mv = ft_itoa(map_c->mv);
			fill_window(map_c);
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
