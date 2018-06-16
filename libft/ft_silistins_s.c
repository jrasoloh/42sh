/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_silistins_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:33:08 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/07 16:21:10 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_silist		*ft_silistins_s(t_silist **list, int data,
		int (*cmp)(int d, int d2))
{
	t_silist	*new;
	t_silist	*before;

	new = ft_silistnew(data);
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
