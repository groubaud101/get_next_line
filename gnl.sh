# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    gnl.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 10:59:00 by groubaud          #+#    #+#              #
#    Updated: 2021/06/20 20:25:15 by groubaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

gcc -I. -D BUFFER_SIZE=$1 -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c;
./a.out $2
 rm a.out
# echo "\n"
# cat $1
