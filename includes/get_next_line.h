/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:45:00 by alex              #+#    #+#             */
/*   Updated: 2022/06/20 22:33:10 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>

char	*get_next_line(int fd);
int		is_bsn(char *dest);
int		ft_strlen(const char *str);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *str);
char	*ft_strcat(char *s1, char *s2);
void	clean_buf(char *str);
void	*ft_memset(void *s, int c, size_t n);

#endif
