/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:43:34 by ajeanne           #+#    #+#             */
/*   Updated: 2022/11/30 12:22:17 by ajeanne          ###   ########.fr       */
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
	dest = ft_calloc(ft_strlen(str) - 1, 1);
	if (!dest)
		return (NULL);
	while (str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	return (free(str), dest);
}
