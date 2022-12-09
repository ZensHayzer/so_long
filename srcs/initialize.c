/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:21:30 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/08 20:32:08 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	map_content_initializer(t_map_content *map_content)
{
	int		fd;
	char	*line;

	map_content->tot_lines = 0;
	fd = open(map_content->map_name, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map_content->tot_lines++;
	}
	map_content->walls = 0;
	map_content->items = 0;
	map_content->exit = 0;
	map_content->start = 0;
	map_content->lines_len = 0;
	map_content->player_x = 0;
	map_content->player_y = 0;
	map_content->map = NULL;
	return (1);
}

void	access_checker_initializer(t_map_content *map_content,
	t_map_content *map_content_copy)
{
	int	i;
	int	j;

	i = 0;
	map_content_copy->items = 0;
	map_content_copy->exit = 0;
	while (i < map_content->tot_lines)
	{
		j = 0;
		while (j < map_content->lines_len)
		{
			if (map_content->map[i][j] == 'P')
			{
				map_content_copy->walls = j;
				map_content_copy->start = i;
			}
			j++;
		}
		i++;
	}
	return ;
}
