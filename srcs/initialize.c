/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:21:30 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/23 03:37:43 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	total_lines(t_map_content *map_content)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map_content->map_name, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

int	map_content_initializer(t_map_content *map_content)
{
	map_content->tot_lines = total_lines(map_content);
	map_content->walls = 0;
	map_content->items = 0;
	map_content->exit = 0;
	map_content->start = 0;
	map_content->enc = 0;
	map_content->cnt = 0;
	map_content->i = 0;
	map_content->j = 0;
	map_content->items_got = 0;
	map_content->last_pos = 0;
	map_content->lines_len = 0;
	map_content->player_x = 0;
	map_content->player_y = 0;
	map_content->mv = 0;
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

int	if_monster_init(t_map_content *map_c, t_mon **mon, int nb, t_mon **tmp)
{
	if (nb == 0)
	{
		*mon = ft_lstnew();
		if (!(*mon))
			return (0);
		(*mon)->mon_y = map_c->i;
		(*mon)->mon_x = map_c->j;
		*tmp = *mon;
	}
	else
	{
		if (!ft_lstaddback(mon, ft_lstnew()))
			return (0);
		while ((*mon)->next)
			*mon = (*mon)->next;
		(*mon)->mon_y = map_c->i;
		(*mon)->mon_x = map_c->j;
		*mon = *tmp;
	}
	return (1);
}

int	monster_init(t_map_content *map_c, t_mon **mon)
{
	int		nb;
	t_mon	*tmp;

	nb = 0;
	map_c->i = 0;
	while (map_c->i < map_c->tot_lines)
	{
		map_c->j = 0;
		while (map_c->j < map_c->lines_len)
		{
			if (map_c->map[map_c->i][map_c->j] == 'M')
			{
				if (!if_monster_init(map_c, mon, nb, &tmp))
					return (0);
				nb++;
			}
			map_c->j++;
		}
		map_c->i++;
	}
	return (1);
}
