/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:17:59 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/04 12:43:07 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t count;

	if (n == 0)
		return (0);
	count = 0;
	while (s1[count] == s2[count] && s1[count] != '\0' && count < n - 1)
	{
		count++;
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
