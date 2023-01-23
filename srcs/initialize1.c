/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:59:45 by ajeanne           #+#    #+#             */
/*   Updated: 2023/01/23 16:04:23 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	img_init(t_map_content *map_content)
{
	map_content->img.enc = NULL;
	map_content->img.exit = NULL;
	map_content->img.exit_o = NULL;
	map_content->img.ground = NULL;
	map_content->img.item = NULL;
	map_content->img.p1 = NULL;
	map_content->img.p2 = NULL;
	map_content->img.p3 = NULL;
	map_content->img.p4 = NULL;
	map_content->img.p_a = NULL;
	map_content->img.p_d = NULL;
	map_content->img.p_w = NULL;
	map_content->img.wall = NULL;
	map_content->mons = NULL;
	return (1);
}
