/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:56:49 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/23 00:55:36 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
// #include <time.h>

int	monster_move_up(t_map_content *map_c, t_mon *mon)
{
	if (map_c->map[mon->mon_y - 1][mon->mon_x] != '1'
		&& map_c->map[mon->mon_y - 1][mon->mon_x] != 'M')
	{
		if (map_c->map[mon->mon_y - 1][mon->mon_x] == 'P')
			free_closing(map_c, &map_c->vars);
		if (mon->last_pos == 'E')
			map_c->map[mon->mon_y][mon->mon_x] = 'E';
		else if (mon->last_pos == 'C')
			map_c->map[mon->mon_y][mon->mon_x] = 'C';
		else
			map_c->map[mon->mon_y][mon->mon_x] = '0';
		mon->last_pos = map_c->map[mon->mon_y - 1][mon->mon_x];
		map_c->map[mon->mon_y - 1][mon->mon_x] = 'M';
		mon->mon_y = mon->mon_y - 1;
		return (1);
	}
	return (0);
}

int	monster_move_left(t_map_content *map_c, t_mon *mon)
{
	if (map_c->map[mon->mon_y][mon->mon_x - 1] != '1'
		&& map_c->map[mon->mon_y][mon->mon_x - 1] != 'M')
	{
		if (map_c->map[mon->mon_y][mon->mon_x - 1] == 'P')
			free_closing(map_c, &map_c->vars);
		if (mon->last_pos == 'E')
			map_c->map[mon->mon_y][mon->mon_x] = 'E';
		else if (mon->last_pos == 'C')
			map_c->map[mon->mon_y][mon->mon_x] = 'C';
		else
			map_c->map[mon->mon_y][mon->mon_x] = '0';
		mon->last_pos = map_c->map[mon->mon_y][mon->mon_x - 1];
		map_c->map[mon->mon_y][mon->mon_x - 1] = 'M';
		mon->mon_x = mon->mon_x - 1;
		return (1);
	}
	return (0);
}

int	monster_move_right(t_map_content *map_c, t_mon *mon)
{
	if (map_c->map[mon->mon_y][mon->mon_x + 1] != '1'
		&& map_c->map[mon->mon_y][mon->mon_x + 1] != 'M')
	{
		if (map_c->map[mon->mon_y][mon->mon_x + 1] == 'P')
			free_closing(map_c, &map_c->vars);
		if (mon->last_pos == 'E')
			map_c->map[mon->mon_y][mon->mon_x] = 'E';
		else if (mon->last_pos == 'C')
			map_c->map[mon->mon_y][mon->mon_x] = 'C';
		else
			map_c->map[mon->mon_y][mon->mon_x] = '0';
		mon->last_pos = map_c->map[mon->mon_y][mon->mon_x + 1];
		map_c->map[mon->mon_y][mon->mon_x + 1] = 'M';
		mon->mon_x = mon->mon_x + 1;
		return (1);
	}
	return (0);
}

int	monster_move_down(t_map_content *map_c, t_mon *mon)
{
	if (map_c->map[mon->mon_y + 1][mon->mon_x] != '1'
		&& map_c->map[mon->mon_y + 1][mon->mon_x] != 'M')
	{
		if (map_c->map[mon->mon_y + 1][mon->mon_x] == 'P')
			free_closing(map_c, &map_c->vars);
		if (mon->last_pos == 'E')
			map_c->map[mon->mon_y][mon->mon_x] = 'E';
		else if (mon->last_pos == 'C')
			map_c->map[mon->mon_y][mon->mon_x] = 'C';
		else
			map_c->map[mon->mon_y][mon->mon_x] = '0';
		mon->last_pos = map_c->map[mon->mon_y + 1][mon->mon_x];
		map_c->map[mon->mon_y + 1][mon->mon_x] = 'M';
		mon->mon_y = mon->mon_y + 1;
		return (1);
	}
	return (0);
}

int	monster_move(t_map_content *map_c)
{
	int	rd;
	int	i;
	t_mon	*tmp;

	i = 0;
	tmp = map_c->mons;
	while (i < map_c->enc)
	{
		rd = rand() % 4;
		if (rd == 0)
			monster_move_up(map_c, map_c->mons);
		else if (rd == 1)
			monster_move_left(map_c, map_c->mons);
		else if (rd == 2)
			monster_move_right(map_c, map_c->mons);
		else if (rd == 3)
			monster_move_down(map_c, map_c->mons);
		i++;
		if (map_c->mons->next)
			map_c->mons = map_c->mons->next;
	}
	map_c->mons = tmp;
	return (0);
}
