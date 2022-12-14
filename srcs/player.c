/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:30:09 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/13 22:38:50 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	p_up(t_map_content *map_c)
{
	if (map_c->map[map_c->player_y + 1][map_c->player_y] != '1')
	{
		if (map_c->map[map_c->player_y + 1][map_c->player_y] == 'C')
			map_c->items_got = map_c->items_got + 1;
		
	}
	return (0);
}

int	player_move(char c, t_map_content *map_c)
{
	if (c == 'w')

	else if (c == 'a')

	else if (c == 's')

	else if (c == 'd')
}
