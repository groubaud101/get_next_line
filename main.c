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

#define AUTRE 1

#if AUTRE
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
	fd++;
	while ((ret = get_next_line(42, &line)) > 0 && ct > 0)
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
	printf("line (%02i) %02i : |%s|\n", ret, i, line);
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (1);
}
#endif

#if !AUTRE

int main()
{
	char *str;

	printf("debut |%p|\n", str);
	if (str == NULL)
		printf("str == NULL\n");
	if (!str)
		printf("!str\n");

	str = NULL;
	printf("\nstr = NULL : |%p|\n", str);
	if (str == NULL)
		printf("str == NULL\n");
	if (!str)
		printf("!str\n");

	str = malloc(10);
	printf("\nstr = malloc(10) : |%p|\n", str);
	if (str == NULL)
		printf("str == NULL\n");
	if (!str)
		printf("!str\n");

	free(str);
	printf("\nfree(str) : |%p|\n", str);
	if (str == NULL)
		printf("str == NULL\n");
	if (!str)
		printf("!str\n");
}
#endif