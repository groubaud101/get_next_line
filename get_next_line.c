/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:13:27 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/18 22:34:07 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static int	ft_separate(char *tmp, char *buff, char **line)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	len;

	if (tmp == NULL)
		tmp = buff;
	i = -1;
	len = ft_isinstr('\n', tmp);
	if (len == -1)
		len = ft_strlen(tmp);
	*line = (char *)malloc(sizeof(**line) + (len + 1));
	if (!(*line))
		return (-1);
	while (tmp[++i] && tmp[i] != '\n')
		(*line)[i] = tmp[i];
	(*line)[i] = '\0';
	i = i + (tmp[i] != '\0');
	j = -1;
	while (tmp[i + ++j])
		buff[j] = tmp[i + j];
	buff[j] = '\0';
	return (1);
}

static int	ft_free(char *tmp, char *buff, int to_free)
{
	if (to_free == 1)
	{
		free(buff);
		buff = NULL;
	}
	free(tmp);
	tmp = NULL;
	return (-1);
}

static int	get_next_line_part(char **tmp, char *buff, int fd, ssize_t *rd)
{
	*rd = 1;
	*tmp = ft_strdup(buff);
	if (!(*tmp))
		return (-1);
	while (ft_isinstr('\n', buff) < 0 && *rd > 0)
	{
		*rd = read(fd, buff, BUFFER_SIZE);
		if (*rd < 0)
			return (-1);
		if (*rd == 0)
			break ;
		buff[*rd] = '\0';
		*tmp = ft_strjoin_gnl(*tmp, buff);
		if (!(*tmp))
			return (-1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff = NULL;
	ssize_t		rd;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (ft_free(tmp, buff, 1));
	if (!buff && BUFFER_SIZE > 0)
	{
		buff = (char *)malloc(sizeof(*buff) * (BUFFER_SIZE + 1));
		if (!buff)
			return (-1);
		buff[0] = '\0';
	}
	if (get_next_line_part(&tmp, buff, fd, &rd) == -1)
		return (ft_free(tmp, buff, 1));
	if (ft_separate(tmp, buff, line) == -1)
		return (ft_free(tmp, buff, 1));
	ft_free(tmp, buff, 0);
	return (rd > 0);
}
