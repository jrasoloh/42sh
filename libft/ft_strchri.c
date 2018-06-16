/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:34:30 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:44 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchri(const char *s, int c)
{
	char	c_char;
	int		i;

	c_char = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c_char)
			return (i);
		i++;
	}
	return (-1);
}
