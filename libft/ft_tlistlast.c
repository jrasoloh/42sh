/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlistlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:44:36 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:21:16 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tlist	*ft_tlistlast(t_tlist *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}
