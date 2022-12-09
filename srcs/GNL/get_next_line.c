/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:46:40 by alex              #+#    #+#             */
/*   Updated: 2022/11/29 23:17:37 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/get_next_line.h"

int	is_bsn(char *dest)
{
	int	i;

	i = 0;
	while (dest && dest[i])
	{
		if (dest[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

void	clean_buf(char *str)
{
	int	i;
	int	j;

	i = is_bsn(str);
	j = 0;
	if (!i || (str && !(*str)))
	{
		free(str);
		str = NULL;
		return ;
	}
	else if (i)
	{
		while (str[i])
		{
			str[j] = str[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
}

char	*reading(int *ret, char *save, int fd)
{
	char	*buf;

	buf = ft_calloc(sizeof(*buf), BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	*ret = read(fd, buf, BUFFER_SIZE);
	if (*ret < 0 || (*ret == 0 && !(save)))
		return (free(buf), NULL);
	save = ft_strdup(buf);
	if (!(save))
		return (NULL);
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*dest;
	int			ret;

	dest = NULL;
	ret = 1;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	if (save && !save[0])
	{
		free(save);
		save = NULL;
	}
	while (ret > 0)
	{
		if (save)
			dest = ft_strcat(dest, save);
		if (is_bsn(dest))
			return (dest);
		save = reading(&ret, save, fd);
		if (!save)
			return (NULL);
	}
	return (dest);
}
