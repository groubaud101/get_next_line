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
#include <unistd.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	int		ct;
	int		ret1;
	int		ret2;
	int		ret3;
	int		i = 0;

	ct = 100;
	ct++;
	if (ac == 0)
		return (0);
	line = NULL;
	ret1 = 1;
	ret2 = 1;
	ret3 = 1;
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	while ((ret1 > 0 || ret2 > 0 || ret3 > 0) && ct > 0)
	{
		if (ret1 <= 0)
			close(fd);
		else
		{
			ret1 = get_next_line(fd, &line);
			printf("line %i (%02i) %02i : |%s|_\n", fd, ret1, i, line);
			free(line);
			line = NULL;
		}
		if (ret2 <= 0)
			close(fd2);
		else
		{
			ret2 = get_next_line(fd2, &line);
			printf("line %i (%02i) %02i : |%s|_\n", fd2, ret2, i, line);
			free(line);
			line = NULL;
		}
		if (ret3 <= 0)
			close(fd3);
		else
		{
			ret3 = get_next_line(fd3, &line);
			printf("line %i (%02i) %02i : |%s|_\n", fd3, ret3, i, line);
			free(line);
			line = NULL;
		}
		i++;
		ct--;
		free(line);
		line = NULL;
	}
	// if (line)
	// {
	// 	free(line);
	// 	line = NULL;
	// }
	return (1);
}
