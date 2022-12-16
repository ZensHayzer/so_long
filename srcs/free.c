/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:10:01 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/16 18:53:01 by ajeanne          ###   ########.fr       */
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

void	free_closing(t_map_content *map_c, t_vars *vars)
{
	close_img(&map_c->vars, &map_c->img);
	mlx_destroy_window(map_c->vars.mlx, map_c->vars.win);
	mlx_destroy_display(map_c->vars.mlx);
	if (vars->mlx)
		free(vars->mlx);
	free_map_content(map_c);
	exit(0);
}
