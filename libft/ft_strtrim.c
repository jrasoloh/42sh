/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:21:09 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:46 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		begin_index(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] == '\0' || s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
	{
		i++;
	}
	return (i);
}

static int		end_index(char const *s)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while ((s[i] == '\0' || s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
			&& i > 0)
	{
		i--;
	}
	return (i + 1);
}

char			*ft_strtrim(char const *s)
{
	int		begin;
	int		end;
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
	{
		begin = 0;
		end = 0;
	}
	else
	{
		begin = begin_index(s);
		end = end_index(s);
	}
	if ((str = ft_strnew((end - begin) < 0 ? 0 : end - begin)) == NULL)
		return (NULL);
	i = 0;
	while (begin < end)
	{
		str[i++] = s[begin++];
	}
	return (str);
}
