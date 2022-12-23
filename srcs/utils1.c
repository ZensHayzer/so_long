/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:53:59 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/23 00:48:59 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_mon	*ft_lstnew()
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
