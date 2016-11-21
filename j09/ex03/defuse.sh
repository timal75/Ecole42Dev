#!/bin/sh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    defuse.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblancha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/09 16:26:38 by jblancha          #+#    #+#              #
#    Updated: 2016/09/09 16:26:38 by jblancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


if [[ ( ! -f "bomb.txt" ) || ( ! -r "bomb.txt" ) ]]
then
	echo "bomb.txt n'est pas un fichier ordinaire ou n'est pas accessible en lecture"
	exit 2
else
	stat -s bomb.txt | awk -F' ' '{print $9}'| awk -F'=' '{print ($2 - 1)}'
fi
