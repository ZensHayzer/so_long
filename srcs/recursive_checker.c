/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:42:13 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/09 15:35:02 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	exit_checker(char **map, int **bool_map, int y, int x)
{
	if (bool_map[y][x] == 1)
		return (0);
	bool_map[y][x] = 1;
	if (map[y + 1][x] == 'E'
		|| map[y - 1][x] == 'E'
		|| map[y][x + 1] == 'E'
		|| map[y][x - 1] == 'E')
		return (1);
	if ((bool_map[y + 1][x] == 0 && exit_checker(map, bool_map, y + 1, x))
		|| (bool_map[y - 1][x] == 0 && exit_checker(map, bool_map, y - 1, x))
		|| (bool_map[y][x + 1] == 0 && exit_checker(map, bool_map, y, x + 1))
		|| (bool_map[y][x - 1] == 0 && exit_checker(map, bool_map, y, x - 1)))
		return (1);
	return (0);
}

int	collectibles_checker(t_map_content *map_content, int **bool_map, int y, int x)
{
	int	cnt;

	cnt = 0;
	if (bool_map[y][x] == 1)
		return (0);
	bool_map[y][x] = 1;
	if (map_content->map[y][x] == 'C')
		cnt++;
	if (bool_map[y + 1][x] == 0)
		cnt += collectibles_checker(map_content, bool_map, y + 1, x);
	if (bool_map[y - 1][x] == 0)
		cnt += collectibles_checker(map_content, bool_map, y - 1, x);
	if (bool_map[y][x + 1] == 0)
		cnt += collectibles_checker(map_content, bool_map, y, x + 1);
	if (bool_map[y][x - 1] == 0)
		cnt += collectibles_checker(map_content, bool_map, y, x - 1);
	return (cnt);
}
