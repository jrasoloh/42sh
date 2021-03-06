/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisblank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:58:11 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/01 12:09:18 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strisblank(const char *s)
{
	while (*s)
	{
		if (*s != '\t' && *s != ' ' && *s != '\r')
			return (0);
		s++;
	}
	return (1);
}
