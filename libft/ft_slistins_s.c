/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slistins_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:30:01 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/07 16:21:21 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist		*ft_slistins_s(t_slist **list, void *data,
		int (*cmp)(void *d, void *d2))
{
	t_slist	*new;
	t_slist	*before;

	new = ft_slistnew(data);
	before = NULL;
	if (list == NULL)
		return (new);
	while (*list != NULL)
	{
		if (cmp(new->data, (*list)->data) < 0)
			break ;
		before = *list;
		list = &((*list)->next);
	}
	if (before == NULL)
	{
		new->next = *list;
		*list = new;
		return (new);
	}
	new->next = before->next;
	before->next = new;
	return (new);
}
