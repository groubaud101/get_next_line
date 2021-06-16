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
	char	*line;
	int		ct;
	int		ret;
	int		i = 0;

	ct = 10;
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
