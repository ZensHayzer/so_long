/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:43:34 by ajeanne           #+#    #+#             */
/*   Updated: 2022/12/13 22:28:15 by ajeanne          ###   ########.fr       */
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
