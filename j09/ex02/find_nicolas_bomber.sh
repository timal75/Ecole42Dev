# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_nicolas_bomber.sh                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblancha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/08 21:49:54 by jblancha          #+#    #+#              #
#    Updated: 2016/09/08 22:11:15 by jblancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if test $# -ne 1 
then
	     echo "Nombre Arguments Incorrects\n"
		 exit 1;
fi
if [[ ! -f "$1" ]]
then
	    echo " $1 Fichier pas accesible en lecture\n"
		exit 1;
fi

cat $1 | grep -i "bomber" |grep -i "nicolas" | awk -F'\t' '{print $3}' |awk -F'[^0-9]*' '$1'

