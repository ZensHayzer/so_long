/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:20:25 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/16 19:05:30 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int	wall_checker(t_map_content *map_content)
{
	int	i;

	i = 0;
	while (i < map_content->lines_len)
	{
		if (map_content->map[0][i] != '1'
			|| map_content->map[map_content->tot_lines - 1][i] != '1')
			return (wall_checker_error(1));
		i++;
	}
	i = 0;
	while (i < map_content->tot_lines)
	{
		if (map_content->map[i][0] != '1'
			|| map_content->map[i][map_content->lines_len - 1] != '1')
			return (wall_checker_error(1));
		i++;
	}
	return (1);
}

int	pre_check_wrong_map(t_map_content *map_content)
{
	int		fd;
	char	*buf;
	int		ret;
	int		i;

	i = 0;
	buf = ft_calloc_so(4, sizeof(char));
	if (!buf)
		return (0);
	fd = open(map_content->map_name, O_RDONLY);
	if (fd < 0)
		return (free(buf), 0);
	ret = read(fd, buf, 3);
	if (ret != 3)
		return (free(buf), 0);
	close(fd);
	while (buf && buf[i])
	{
		if (buf[i] != '1')
			return (pre_check_wrong_map_error(buf, 1));
		i++;
	}
	return (free(buf), 1);
}

void	player_position(t_map_content *map_content, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_content->tot_lines)
	{
		j = 0;
		while (j < map_content->lines_len)
		{
			if (map_content->map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	access_checker(t_map_content *map_content)
{
	int	**bool_map;

	bool_map = init_boolmap(map_content->map, map_content->tot_lines,
			map_content->lines_len);
	if (!bool_map)
		return (0);
	player_position(map_content, &map_content->player_x,
		&map_content->player_y);
	if (!exit_checker(map_content->map, bool_map, map_content->player_y,
			map_content->player_x))
		return (access_checking_error(1, bool_map, map_content->tot_lines));
	player_position(map_content, &map_content->player_x,
		&map_content->player_y);
	fill_boolmap(map_content->map, bool_map, map_content->tot_lines,
		map_content->lines_len);
	if (collectibles_checker(map_content, bool_map, map_content->player_y,
			map_content->player_x) != map_content->items)
		return (access_checking_error(1, bool_map, map_content->tot_lines));
	return (free_boolmap(bool_map, map_content->tot_lines), 1);
}
