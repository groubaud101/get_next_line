/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:13:42 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/13 10:13:42 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isinstr(char c, const char *str)
{
	int		index;

	if (c == '\0')
		return (-1);
	index = 0;
	while (str[index])
	{
		if (c == str[index])
			return (index);
		index++;
	}
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (!str[i])
			return (i);
		else if (!str[i + 1])
			return (i + 1);
		else if (!str[i + 2])
			return (i + 2);
		else if (!str[i + 3])
			return (i + 3);
		else if (!str[i + 4])
			return (i + 4);
		else if (!str[i + 5])
			return (i + 5);
		else if (!str[i + 6])
			return (i + 6);
		else if (!str[i + 7])
			return (i + 7);
		else if (!str[i + 8])
			return (i + 8);
		i = i + 9;
	}
}

static char	*ft_strdup(const char *s)
{
	char	*str;
	int		index;

	str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	index = 0;
	while (s[index])
	{
		str[index] = s[index];
		index++;
	}
	str[index] = s[index];
	return (str);
}

static char	*ft_strcat(char *dst, const char *src)
{
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = 0;
	while (src[s])
		dst[d++] = src[s++];
	dst[d] = '\0';
	return (dst);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*dest;
	int		dlen;
	int		len_s1;

	if (!s1 || !s2)
	{
		if (s1)
			return (ft_strdup(s1));
		else if (s2)
			return (ft_strdup(s2));
		return (NULL);
	}
	len_s1 = ft_strlen(s1);
	dlen = len_s1 + ft_strlen(s2);
	dest = (char *)malloc(sizeof(*dest) * (dlen + 1));
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	free(s1);
	s1 = NULL;
	return (dest);
}
