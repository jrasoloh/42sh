/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:22:20 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:42 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		begin_index(const char *str)
{
	int i;

	i = 0;
	while ((str[i] <= ' ' && str[i] != '\e')
			&& (str[i] != '\0' && str[i] != '\200'))
	{
		i++;
	}
	if (((str[i] == '-' || str[i] == '+')
				&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
			|| (str[i] >= '0' && str[i] <= '9'))
		return (i);
	else
		return (-1);
}

static size_t	end_index(const char *str, size_t begin)
{
	size_t i;

	i = begin;
	if (str[begin] == '-' || str[begin] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	return (i - 1);
}

int				ft_atoi(const char *str)
{
	int		begin;
	int		end;
	long	mult;
	long	nb;

	if ((begin = begin_index(str)) == -1)
		return (0);
	end = end_index(str, begin);
	mult = 1;
	nb = 0;
	while (end >= begin && (str[end] >= '0' && str[end] <= '9'))
	{
		if (str[begin] == '-')
			nb -= (str[end] - '0') * mult;
		else
			nb += (str[end] - '0') * mult;
		mult *= 10;
		end--;
	}
	return ((int)nb);
}
