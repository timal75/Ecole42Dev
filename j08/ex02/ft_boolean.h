/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 13:41:21 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/09 15:22:48 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define	TRUE		1
#define	FALSE		0
#define	SUCCESS		0
#define	EVEN_MSG	"J'ai un nombre pair d'arguments.\n"
#define	ODD_MSG		"J'ai un nombre impair d'arguments.\n"
#define	EVEN(x)		(!((x) % 2))

typedef int t_bool;
