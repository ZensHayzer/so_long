/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:31:46 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/09 15:38:07 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <unistd.h>

int	map_checker(t_map_content *map_content)
{
	if (!ber_checker(map_content->map_name))
		return (map_checker_error(1));
	if (!pre_check_wrong_map(map_content))
		return (0);
	if (!map_content_initializer(map_content))
		return (0);
	if (!map_builder(map_content))
		return (0);
	if (!lines(map_content))
		return (0);
	if (!present_char(map_content))
		return (0);
	if (!wall_checker(map_content))
		return (0);
	if (!access_checker(map_content))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map_content	*map_content;

	if (argc == 2)
	{
		map_content = malloc(sizeof(t_map_content));
		if (!map_content)
			return (0);
		map_content->map_name = argv[1];
		if (!map_checker(map_content))
			return (0);
	}
	return (0);
}
