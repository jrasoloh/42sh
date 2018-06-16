/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:23:01 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/08 14:11:04 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pathjoin(const char *p1, const char *p2)
{
	char	*p1_slash;
	char	*path;

	if (p1[ft_strlen(p1) - 1] != '/')
	{
		p1_slash = ft_strjoin((const char*)p1, "/");
		path = ft_strjoin((const char*)p1_slash, p2);
		ft_strdel(&p1_slash);
	}
	else
		path = ft_strjoin((const char*)p1, p2);
	return (path);
}
