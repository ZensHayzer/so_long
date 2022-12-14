/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:47:07 by alex              #+#    #+#             */
/*   Updated: 2022/12/13 15:33:10 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/get_next_line.h"

int	ft_strlen(const char *str)
{
	char	*tmp;

	if (!str || !(*str))
		return (0);
	tmp = (char *)str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(nmemb * (size + 1));
	if (!dest)
		return (NULL);
	while (i <= (int)size)
		dest[i++] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = ft_calloc(sizeof(*dest), ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}

char	*ft_strcat(char *s1, char *s2)
{
	char		*dest;
	const int	len = ft_strlen(s1) + ft_strlen(s2);
	int			i;
	int			j;

	i = 0;
	j = 0;
	dest = ft_calloc(sizeof(*dest), len + 1);
	if (!dest)
		return (NULL);
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		dest[i + j] = s2[j];
		if (s2[j] == '\n')
			break ;
		j++;
	}
	if (s1)
		free(s1);
	return (clean_buf(s2), dest);
}
