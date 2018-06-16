/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:02:30 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:45 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hi;
	size_t	ni;
	size_t	matchi;

	hi = 0;
	ni = 0;
	matchi = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[hi] != '\0' && hi < len)
	{
		matchi = hi;
		while (haystack[hi] == needle[ni] && hi < len && ni < ft_strlen(needle))
		{
			hi++;
			ni++;
		}
		if (ni == ft_strlen(needle))
			return ((char*)&(haystack[matchi]));
		hi = matchi + 1;
		ni = 0;
	}
	return (NULL);
}
