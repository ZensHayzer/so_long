/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:57:35 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/23 01:02:52 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_monster_lst(t_mon *mon)
{
	void	*tmp;

	if (!mon)
		return ;
	while (mon)
	{
		tmp = mon->next;
		free(mon);
		mon = tmp;
	}
}
