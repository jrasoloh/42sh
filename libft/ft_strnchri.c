/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:34:30 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/20 11:53:26 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnchri(const char *s, int c, int n)
{
	char	c_char;
	int		i;

	c_char = (char)c;
	i = n;
	while (s[i] != '\0')
	{
		if (s[i] == c_char)
			return (i);
		i++;
	}
	return (-1);
}
