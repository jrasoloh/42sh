/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:25:42 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:45 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strext(char **s, size_t size)
{
	char	*buf;
	size_t	s_len;

	s_len = ft_strlen(*s);
	if ((buf = ft_strnew(s_len + size)))
		return (-1);
	ft_strcpy(buf, *s);
	free(*s);
	*s = buf;
	return (s_len + size);
}
