/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:29:06 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/16 13:29:06 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	int		ct;
	int		ret;
	int		i = 0;

	ct = 10;
	ct++;
	if (ac == 0)
		return (0);
	line = NULL;
	ret = 1;
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	while (ret > 0 && ct > 0)
	{
		ret = get_next_line(fd, &line);
		printf("line %i (%02i) %02i : |%s|\n", fd, ret, i, line);
		ret = get_next_line(fd2, &line);
		printf("line %i (%02i) %02i : |%s|\n", fd2, ret, i, line);
		ret = get_next_line(fd3, &line);
		printf("line %i (%02i) %02i : |%s|\n", fd3, ret, i, line);
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
