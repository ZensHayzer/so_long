/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:50:41 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/17 12:41:14 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ber_checker(char *str)
{
	int	i;

	if (str)
	{
		i = ft_strlen(str) - 1;
		if (str[i] == 'r' && str[i - 1] == 'e'
			&& str[i - 2] == 'b' && str[i - 3] == '.')
			return (1);
	}
	return (0);
}

int	map_builder(t_map_content *map_content)
{
	int	fd;
	int	i;

	i = 0;
	map_content->map = malloc(sizeof(char *) * (map_content->tot_lines + 1));
	if (!map_content)
		return (0);
	fd = open(map_content->map_name, O_RDONLY);
	if (fd < 0)
		return (0);
	map_content->map[i] = gnl_corrector(get_next_line(fd));
	while (map_content->map[i])
	{
		i++;
		map_content->map[i] = gnl_corrector(get_next_line(fd));
	}
	return (1);
}

int	lines(t_map_content *map_content)
{
	int	i;

	i = 0;
	if (map_content->tot_lines < 3)
		return (lines_error(1));
	map_content->lines_len = ft_strlen(map_content->map[i]);
	if (map_content->lines_len < 3)
		return (lines_error(2));
	while (map_content->map[i])
	{
		if (ft_strlen(map_content->map[i]) != map_content->lines_len)
			return (lines_error(3));
		i++;
	}
	return (1);
}

int	is_a_good_char(t_map_content *map_content, char c)
{
	if (c == '0')
		return (1);
	else if (c == '1')
		map_content->walls++;
	else if (c == 'C')
		map_content->items++;
	else if (c == 'E')
		map_content->exit++;
	else if (c == 'P')
		map_content->start++;
	else if (c == 'M')
		map_content->enc++;
	else
		return (0);
	return (1);
}

int	present_char(t_map_content *map_content)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_content->tot_lines)
	{
		j = 0;
		while (j < map_content->lines_len)
		{
			if (!is_a_good_char(map_content, map_content->map[i][j]))
				return (present_char_error(1));
			j++;
		}
		i++;
	}
	if (map_content->items < 1)
		return (present_char_error(2));
	if (map_content->exit != 1)
		return (present_char_error(3));
	if (map_content->start != 1)
		return (present_char_error(4));
	return (1);
}
