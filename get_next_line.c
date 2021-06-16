/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:13:27 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/16 12:57:20 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static int	ft_separate(char *tmp, char *buff, char **line)
{
	int	i;
	int	j;
	int	len;
	int	f;

	i = -1;
	f = (tmp != NULL);
	if (tmp == NULL)
		tmp = buff;
	len = ft_isinstr('\n', tmp);
	if (len == -1)
		len = (int)ft_strlen(tmp);
	*line = (char *)malloc(sizeof(**line) * (len + 1));
	if (!(*line))
		return (-1);
	while (tmp[++i] && tmp[i] != '\n')
		(*line)[i] = tmp[i];
	(*line)[i] = '\0';
	i = i + (tmp[i] != '\0');
	j = 0;
	while (tmp[i])
		buff[j++] = tmp[i++];
	buff[j] = '\0';
	if (f)
		free(tmp);
	return (1);
}

static int	ft_free(char *tmp)
{
	if (tmp != NULL)
		free(tmp);
	return (-1);
}

static int	get_next_line_two(char **tmp, char **buff, int fd)
{
	int	rd;
	int	len;

	rd = 1;
	while (ft_isnstr('\n', buff) < 0 && rd > 0)
	{
		rd = read(fd, *buff, BUFFER_SIZE);
		if (rf < 0)
				return (-1);
	}
}
	

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			rd;
	char		*tmp;
	int			len;

	len = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (-1);
	rd = 1;
	tmp = ft_strjoin_gnl(NULL, buff);
	if (!tmp)
		return (-1);
	while (ft_isinstr('\n', buff) < 0 && rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
			return (-1);
		if (rd == 0)
			break ;
		buff[rd] = '\0';
		len += rd;
		tmp = ft_strjoin_gnl(tmp, buff);
		if (!tmp)
			return (-1);
	}
	if (ft_separate(tmp, buff, line) == -1)
		return (ft_free(tmp));
	return (rd > 0);
}
