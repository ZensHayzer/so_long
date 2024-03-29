/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:14:03 by ajeanne           #+#    #+#             */
/*   Updated: 2023/01/21 17:29:04 by ajeanne          ###   ########.fr       */
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
			fill_window(map_c, keycode);
			ft_puterr(mv);
			ft_puterr("\n");
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
