/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoares- <usoares-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:14:33 by usoares-          #+#    #+#             */
/*   Updated: 2021/07/10 23:14:33 by usoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_free_null(char **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

static void		ft_cpy_exc_buff(char **buff, long long j)
{
	long long	i;
	char		temp[ARG_MAX];

	i = 0;
	if (buff[0][j] == '\0')
		ft_free_null(&*buff);
	else
	{
		while (buff[0][j] != '\0')
			temp[i++] = buff[0][j++];
		temp[i] = '\0';
		ft_free_null(&*buff);
		*buff = ft_strdup(temp);
	}
}

static int		ft_buff2line(char **line, char **buff)
{
	long long	i;
	long long	j;
	char		temp[ARG_MAX];

	i = 0;
	j = 0;
	while (line[0][i] != '\0')
	{
		temp[i] = line[0][i];
		i++;
	}
	ft_free_null(&*line);
	while (buff[0][j] != '\0' && buff[0][j] != '\n')
		temp[i++] = buff[0][j++];
	temp[i] = '\0';
	*line = ft_strdup(temp);
	if (buff[0][j] == '\n')
	{
		ft_cpy_exc_buff(&*buff, j + 1);
		return (FOUND_ENDLINE);
	}
	ft_free_null(&*buff);
	return (NO_ENDLINE);
}

int				get_next_line(int fd, char **line)
{
	static char	*buff[OPEN_MAX];
	char		temp[ARG_MAX];
	int			ret[2];

	if (fd >= 0 && line && BUFFER_SIZE > 0 && (*line = ft_strdup("")))
	{
		ret[0] = NO_ENDLINE;
		while (ret[0] == NO_ENDLINE)
		{
			if (buff[fd] == NULL && (ret[1] = read(fd, temp, BUFFER_SIZE)) >= 0
				&& (temp[ret[1]] = '\0') == 0)
				buff[fd] = ft_strdup(temp);
			if (buff[fd] != NULL)
				ret[1] = ft_strlen(buff[fd]);
			if (ret[1] < 0)
				break ;
			ret[0] = ft_buff2line(&*line, &buff[fd]);
			if (ret[1] == 0)
				return (0);
		}
		if (ret[0] == FOUND_ENDLINE)
			return (1);
	}
	ft_free_null(&*line);
	return (-1);
}
