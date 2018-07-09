/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlistlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:45:42 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:18:20 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_tlistlen(t_tlist *list)
{
	size_t	size;

	size = 0;
	while (list != NULL)
	{
		list = list->next;
		size++;
	}
	return (size);
}
