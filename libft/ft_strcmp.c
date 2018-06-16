/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:10:12 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/04 11:58:45 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int count;

	count = 0;
	while (s1[count] == s2[count] && s1[count] != '\0')
	{
		if (s2[count] == '\0')
			return (s1[count]);
		count++;
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
