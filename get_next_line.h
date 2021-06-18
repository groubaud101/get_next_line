/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:13:59 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/15 23:33:46 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "wraloc.h"

char	*ft_strjoin_gnl(char *s1, char const *s2);
int		ft_isinstr(char c, const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);

int		get_next_line(int fd, char **line);

#endif
