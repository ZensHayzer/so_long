/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:16:30 by ajeanne           #+#    #+#             */
/*   Updated: 2023/01/20 17:31:24 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <unistd.h>

int	map_checker_error(int err)
{
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("Map file has to be a .ber\n");
	if (err == 2)
		ft_puterr("No access to the file / not a map\n");
	if (err == 3)
		ft_puterr("No env found\n");
	return (0);
}

int	lines_error(int err)
{
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("Map need atleast 3 lines\n");
	if (err == 2)
		ft_puterr("Need atleast 3 columns\n");
	if (err == 3)
		ft_puterr("All horizontal lanes needs same lenght\n");
	return (0);
}

int	present_char_error(int err)
{
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("You can only use '0', '1', 'C', 'E' and 'P' char\n");
	if (err == 2)
		ft_puterr("You must place 1 or more collectibles\n");
	if (err == 3)
		ft_puterr("You must place one, and only one exit\n");
	if (err == 4)
		ft_puterr("You must place one, and only one start\n");
	return (0);
}

int	wall_checker_error(int err)
{
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("All map borders must be walls\n");
	return (0);
}

int	pre_check_wrong_map_error(char *buf, int err)
{
	if (buf)
		free(buf);
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("Map non valide\n");
	return (0);
}
