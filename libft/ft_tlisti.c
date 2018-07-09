/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlisti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:50:28 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:19:41 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tlisti(t_tlist *list)
{
	t_tlist	*iter;
	int		i;

	iter = list;
	i = 0;
	while (iter != NULL)
	{
		iter = iter->prev;
		i++;
	}
	return (i);
}
