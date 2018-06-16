/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slistadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:02:08 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/06 13:10:49 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist	*ft_slistadd(t_slist **list, void *data)
{
	t_slist	*new;

	if ((new = ft_slistnew(data)) == NULL)
		return (NULL);
	new->next = *list;
	*list = new;
	return (*list);
}
