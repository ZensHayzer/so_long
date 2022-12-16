/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:43:34 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/16 19:19:20 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_puterr(char *str)
{
	write(2, str, ft_strlen(str));
}

char	*gnl_corrector(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	dest = ft_calloc_so(ft_strlen(str), 1);
	if (!dest)
		return (NULL);
	while (str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	return (free(str), dest);
}

char	*ft_calloc_so(size_t nmemb, size_t size)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((nmemb + 1) * size);
	if (!dest)
		return (NULL);
	while (i < (int)nmemb)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	is_in(char *str, char c)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	fill_window_forest(t_map_content *map_c, t_vars vars, int i, int j)
{
	if (map_c->map[i][j] == '1')
		mlx_put_image_to_window(vars.mlx, vars.win, map_c->img.wall,
			j * map_c->img.x_size, i * map_c->img.y_size);
	else if (map_c->map[i][j] == '0')
		mlx_put_image_to_window(vars.mlx, vars.win, map_c->img.ground,
			j * map_c->img.x_size, i * map_c->img.y_size);
	else if (map_c->map[i][j] == 'P')
		mlx_put_image_to_window(vars.mlx, vars.win, map_c->img.player,
			j * map_c->img.x_size, i * map_c->img.y_size);
	else if (map_c->map[i][j] == 'C')
		mlx_put_image_to_window(vars.mlx, vars.win, map_c->img.item,
			j * map_c->img.x_size, i * map_c->img.y_size);
	else if (map_c->map[i][j] == 'E')
		mlx_put_image_to_window(vars.mlx, vars.win, map_c->img.exit,
			j * map_c->img.x_size, i * map_c->img.y_size);
}
