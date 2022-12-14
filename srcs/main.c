/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:31:46 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/14 18:41:30 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/**
 * @brief Check the map
 *
 * @param map_content Take a struct with all values
 * @return int true or false
 */
int	map_checker(t_map_content *map_content)
{
	if (!ber_checker(map_content->map_name))
		return (map_checker_error(1));
	if (!pre_check_wrong_map(map_content))
		return (false);
	if (!map_content_initializer(map_content))
		return (false);
	if (!map_builder(map_content))
		return (false);
	if (!lines(map_content))
		return (false);
	if (!present_char(map_content))
		return (false);
	if (!wall_checker(map_content))
		return (false);
	if (!access_checker(map_content))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_map_content	map_content;

	if (argc == 2)
	{
		map_content.map_name = argv[1];
		if (!map_checker(&map_content))
			return (free_map_content(&map_content), EXIT_FAILURE);
	}
	window(&map_content);
	return (free_map_content(&map_content), EXIT_SUCCESS);
}
