/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:12:56 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:45 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1_i;
	size_t	s2_i;

	s1_i = ft_strlen(s1);
	s2_i = 0;
	while (s2[s2_i] != '\0' && s2_i < n)
	{
		s1[s1_i] = s2[s2_i];
		s1_i++;
		s2_i++;
	}
	s1[s1_i] = '\0';
	return (s1);
}
