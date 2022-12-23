/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:10:01 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/23 01:04:19 by ajeanne          ###   ########.fr       */
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
	free_monster_lst(map_c->mons);
	exit(0);
}

void	close_img_1(t_vars *vars, t_images *img)
{
	if (img->p_d)
		mlx_destroy_image(vars->mlx, img->p_d);
	if (img->p_w)
		mlx_destroy_image(vars->mlx, img->p_w);
	if (img->p_a)
		mlx_destroy_image(vars->mlx, img->p_a);
	if (img->exit_o)
		mlx_destroy_image(vars->mlx, img->exit_o);
}

void	close_img(t_vars *vars, t_images *img)
{
	if (img->exit)
		mlx_destroy_image(vars->mlx, img->exit);
	if (img->item)
		mlx_destroy_image(vars->mlx, img->item);
	if (img->p1)
		mlx_destroy_image(vars->mlx, img->p1);
	if (img->p2)
		mlx_destroy_image(vars->mlx, img->p2);
	if (img->p3)
		mlx_destroy_image(vars->mlx, img->p3);
	if (img->p4)
		mlx_destroy_image(vars->mlx, img->p4);
	if (img->ground)
		mlx_destroy_image(vars->mlx, img->ground);
	if (img->wall)
		mlx_destroy_image(vars->mlx, img->wall);
	if (img->enc)
		mlx_destroy_image(vars->mlx, img->enc);
	close_img_1(vars, img);
}
