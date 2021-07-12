/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoares- <usoares-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:14:59 by usoares-          #+#    #+#             */
/*   Updated: 2021/07/10 23:14:59 by usoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t l;

	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + 1;
	if (!(s2 = (char *)malloc(size)))
		return (0);
	i = 0;
	while (i < size)
	{
		((unsigned char *)s2)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	return (s2);
}
