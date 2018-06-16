/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:39:01 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:45 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	begin_word(char const *s, char c, size_t begin)
{
	while (s[begin] != '\0' && s[begin] == c)
		begin++;
	return (begin);
}

static size_t	end_word(char const *s, char c, size_t begin)
{
	while (s[begin] != '\0' && s[begin] != c)
		begin++;
	return (begin);
}

static size_t	nofw(char const *s, char c)
{
	int		nb;
	size_t	i;

	nb = 0;
	i = begin_word(s, c, 0);
	while (s[i] != '\0')
	{
		i = begin_word(s, c, begin_word(s, c, end_word(s, c, i)));
		nb++;
	}
	return (nb);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i_nofw;
	size_t	si;
	size_t	end;
	size_t	wi;

	if (s == NULL)
		return (NULL);
	if ((tab = (char**)malloc(sizeof(char*) * (nofw(s, c) + 1))) == NULL)
		return (NULL);
	tab[nofw(s, c)] = 0;
	i_nofw = 0;
	si = 0;
	while (i_nofw < nofw(s, c))
	{
		si = begin_word(s, c, si);
		end = end_word(s, c, si);
		if ((tab[i_nofw] = ft_strnew(end - si)) == NULL)
			return (NULL);
		wi = 0;
		while (si < end)
			tab[i_nofw][wi++] = s[si++];
		i_nofw++;
	}
	return (tab);
}
