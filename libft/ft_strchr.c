/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:21:19 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:44 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_char;
	size_t	i;

	c_char = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c_char)
		{
			return ((char*)&(s[i]));
		}
		i++;
	}
	if (c_char == '\0')
		return ((char*)&(s[i]));
	return (NULL);
}
