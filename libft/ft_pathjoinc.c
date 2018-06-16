/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoinc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:10:46 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/08 14:10:56 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pathjoinc(const char *p1, const char *p2)
{
	char	*p1_slash;
	char	*path;

	if (ft_strcmp(p1, ".") == 0)
		return (ft_strdup(p2));
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
