/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:30:09 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/09 18:17:55 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <unistd.h>

int	access_checking_error(int err, int **bool_map, int height)
{
	ft_puterr("Error\n");
	if (err == 1)
		ft_puterr("All exits and collectibles must be reachables\n");
	free_boolmap(bool_map, height);
	return (0);
}
