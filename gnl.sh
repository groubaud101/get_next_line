# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    gnl.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 10:59:00 by groubaud          #+#    #+#              #
#    Updated: 2021/06/16 14:19:37 by groubaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

gcc -I. -D BUFFER_SIZE=$2 -std=c11 -ggdb3 -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c;
./	a.out $1
# rm a.out
# echo "\n"
# cat $1
