/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:30:59 by ajeanne           #+#    #+#             */
/*   Updated: 2023/01/21 19:02:02 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdlib.h>

void	free_boolmap(int **bool_map, int height)
{
	int	i;

	i = 0;
	while (i < height && bool_map[i])
	{
		free(bool_map[i]);
		i++;
	}
	free(bool_map);
	return ;
}

void	fill_boolmap(char **map, int **bool_map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == '1')
				bool_map[i][j] = 1;
			else
				bool_map[i][j] = 0;
			j++;
		}
		i++;
	}
	return ;
}

int	**init_boolmap(char **map, int height, int width)
{
	int	**bool_map;
	int	i;

	i = 0;
	bool_map = malloc(sizeof(int *) * height);
	if (!bool_map)
		return (NULL);
	while (i < height)
	{
		bool_map[i] = malloc(sizeof(int) * width);
		if (!bool_map[i])
			return (free_boolmap(bool_map, i), NULL);
		i++;
	}
	fill_boolmap(map, bool_map, height, width);
	return (bool_map);
}
