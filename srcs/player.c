/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:30:09 by ajeanne           #+#    #+#             */
/*   Updated: 2023/01/21 18:15:02 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	p_up(t_map_content *map_c)
{
	if (map_c->map[map_c->player_y - 1][map_c->player_x] != '1')
	{
		if (map_c->map[map_c->player_y - 1][map_c->player_x] == 'C')
			map_c->items_got = map_c->items_got + 1;
		if (map_c->map[map_c->player_y - 1][map_c->player_x] == 'E')
			if (map_c->items_got == map_c->items)
				free_closing(map_c, &map_c->vars);
		if (map_c->last_pos == 'E')
			map_c->map[map_c->player_y][map_c->player_x] = 'E';
		else
			map_c->map[map_c->player_y][map_c->player_x] = '0';
		map_c->last_pos = map_c->map[map_c->player_y - 1][map_c->player_x];
		map_c->map[map_c->player_y - 1][map_c->player_x] = 'P';
		map_c->player_y = map_c->player_y - 1;
		return (1);
	}
	return (0);
}

int	p_left(t_map_content *map_c)
{
	if (map_c->map[map_c->player_y][map_c->player_x - 1] != '1')
	{
		if (map_c->map[map_c->player_y][map_c->player_x - 1] == 'C')
			map_c->items_got = map_c->items_got + 1;
		if (map_c->map[map_c->player_y][map_c->player_x - 1] == 'E')
			if (map_c->items_got == map_c->items)
				free_closing(map_c, &map_c->vars);
		if (map_c->last_pos == 'E')
			map_c->map[map_c->player_y][map_c->player_x] = 'E';
		else
			map_c->map[map_c->player_y][map_c->player_x] = '0';
		map_c->last_pos = map_c->map[map_c->player_y][map_c->player_x - 1];
		map_c->map[map_c->player_y][map_c->player_x - 1] = 'P';
		map_c->player_x = map_c->player_x - 1;
		return (1);
	}
	return (0);
}

int	p_down(t_map_content *map_c)
{
	if (map_c->map[map_c->player_y + 1][map_c->player_x] != '1')
	{
		if (map_c->map[map_c->player_y + 1][map_c->player_x] == 'C')
			map_c->items_got = map_c->items_got + 1;
		if (map_c->map[map_c->player_y + 1][map_c->player_x] == 'E')
			if (map_c->items_got == map_c->items)
				free_closing(map_c, &map_c->vars);
		if (map_c->last_pos == 'E')
			map_c->map[map_c->player_y][map_c->player_x] = 'E';
		else
			map_c->map[map_c->player_y][map_c->player_x] = '0';
		map_c->last_pos = map_c->map[map_c->player_y + 1][map_c->player_x];
		map_c->map[map_c->player_y + 1][map_c->player_x] = 'P';
		map_c->player_y = map_c->player_y + 1;
		return (1);
	}
	return (0);
}

int	p_right(t_map_content *map_c)
{
	if (map_c->map[map_c->player_y][map_c->player_x + 1] != '1')
	{
		if (map_c->map[map_c->player_y][map_c->player_x + 1] == 'C')
			map_c->items_got = map_c->items_got + 1;
		if (map_c->map[map_c->player_y][map_c->player_x + 1] == 'E')
			if (map_c->items_got == map_c->items)
				free_closing(map_c, &map_c->vars);
		if (map_c->last_pos == 'E')
			map_c->map[map_c->player_y][map_c->player_x] = 'E';
		else
			map_c->map[map_c->player_y][map_c->player_x] = '0';
		map_c->last_pos = map_c->map[map_c->player_y][map_c->player_x + 1];
		map_c->map[map_c->player_y][map_c->player_x + 1] = 'P';
		map_c->player_x = map_c->player_x + 1;
		return (1);
	}
	return (0);
}

int	player_move(char c, t_map_content *map_c)
{
	int	ret;

	ret = 0;
	if (c == 'w')
		ret = p_up(map_c);
	else if (c == 'a')
		ret = p_left(map_c);
	else if (c == 's')
		ret = p_down(map_c);
	else if (c == 'd')
		ret = p_right(map_c);
	if (ret == 1)
		map_c->mv++;
	return (ret);
}
