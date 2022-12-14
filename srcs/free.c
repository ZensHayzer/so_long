/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:10:01 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/09 19:38:56 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_map_content(t_map_content *map_content)
{
	int	i;

	i = 0;
	while (i < map_content->tot_lines)
	{
		if (map_content->map[i])
			free(map_content->map[i]);
		i++;
	}
	if (map_content->map)
		free(map_content->map);
}
