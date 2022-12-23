/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:59 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/23 02:27:12 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_mon	*ft_lstnew(void)
{
	t_mon	*new_element;

	new_element = malloc(sizeof(t_mon));
	if (!new_element)
		return (NULL);
	new_element->mon_x = 0;
	new_element->mon_y = 0;
	new_element->last_pos = 0;
	new_element->next = NULL;
	return (new_element);
}

int	ft_lstaddback(t_mon **lst, t_mon *element)
{
	void	*tmp;

	tmp = *lst;
	if (!element)
		return (0);
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = element;
	element->next = NULL;
	*lst = tmp;
	return (1);
}

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
