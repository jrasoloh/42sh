/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:47:34 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:45 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	if (n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if ((s1_len != s2_len && n < s1_len) || (s1_len < s2_len && n > s1_len))
		return (0);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
