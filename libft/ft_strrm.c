/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:08:18 by echojnow          #+#    #+#             */
/*   Updated: 2018/02/27 17:55:56 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrm(char const *s, unsigned int start, size_t len)
{
	unsigned int	end;
	size_t			new_len;
	char			*new;
	unsigned int	ni;
	unsigned int	si;

	end = start + len;
	new_len = (size_t)((int)ft_strlen(s) - len);
	if ((new = ft_strnew(new_len)) == NULL)
		return (NULL);
	ni = 0;
	si = 0;
	while (s[si])
	{
		if (si >= start && si < end)
		{
			si++;
			continue ;
		}
		new[ni] = s[si];
		si++;
		ni++;
	}
	return (new);
}
