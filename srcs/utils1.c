/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:59 by ajeanne           #+#    #+#             */
/*   Updated: 2023/01/21 17:24:21 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	if_forest(t_map_content *map_c, char mv, int i, int j)
{
	if (map_c->map[i][j] == 'P' && mv == 's')
		mlx_put_image_to_window(map_c->vars.mlx, map_c->vars.win,
			map_c->img.p1, j * map_c->img.x_size, i * map_c->img.y_size);
	else if (map_c->map[i][j] == 'P' && mv == 'd')
		mlx_put_image_to_window(map_c->vars.mlx, map_c->vars.win,
			map_c->img.p_d, j * map_c->img.x_size, i * map_c->img.y_size);
	else if (map_c->map[i][j] == 'P' && mv == 'w')
		mlx_put_image_to_window(map_c->vars.mlx, map_c->vars.win,
			map_c->img.p_w, j * map_c->img.x_size, i * map_c->img.y_size);
	else if (map_c->map[i][j] == 'P' && mv == 'a')
		mlx_put_image_to_window(map_c->vars.mlx, map_c->vars.win,
			map_c->img.p_a, j * map_c->img.x_size, i * map_c->img.y_size);
}
