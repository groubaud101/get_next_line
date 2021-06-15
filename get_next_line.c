/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:13:27 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/13 10:13:27 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_separate(char *tmp, char *buff, char **line)
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
}

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			rd;
	char		*tmp;
	int			len;

	len = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 0 || read(fd, buff, 0) < 0)
		return (-1);
	rd = 1;
	tmp = ft_strjoin_gnl(NULL, buff);
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
	ft_separate(tmp, buff, line);
	return (rd > 0);
}

#if 1
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		ct;
	int		ret;
	int		i = 0;

	ct = 200;
	ct++;
	if (ac == 0)
		return (0);
	line = NULL;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0 && ct > 0)
	{
		printf("line (%02i) %02i : |%s|\n", ret, i, line);
		i++;
		ct--;
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	if (line)
	{
		free(line);
		line = NULL;
	}

	return (1);
}
#endif