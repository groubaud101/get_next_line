/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:29:06 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/19 22:50:20 by groubaud         ###   ########.fr       */
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
	ret = 1;
	while (ret > 0 && ct > 0)
	{
	   	ret = get_next_line(fd, &line);
		printf("1line (ret %02i) %02i : |%s|\n%p\n", ret, i, line, line);
		if (line)
		{
			free(line);
			line = NULL;
		}
	   	ret = get_next_line(fd, &line);
		printf("2line (ret %02i) %02i : |%s|\n%p\n", ret, i, line, line);
		if (line)
		{
			free(line);
			line = NULL;
		}
		i++;
		ct--;
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
	
	str = NULL;
	if (!str)
	{
		printf("\nfree x 2 (str) : |%p|\n", str);
		free(str);
	}
	if (str == NULL)
		printf("str == NULL\n");
	if (!str)
		printf("!str\n");

	str = NULL;
	printf("\nstr = NULL2 : |%p|\n", str);
	if (str == NULL)
		printf("str == NULL\n");
	if (!str)
		printf("!str\n");

	str = malloc(10);
	str = NULL;
	printf("\nmalloc(10) = NULL : |%p|\n", str);
	if (str == NULL)
		printf("str == NULL\n");
	if (!str)
		printf("!str\n");


}
#endif
