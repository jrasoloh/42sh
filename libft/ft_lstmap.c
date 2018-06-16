/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:25:03 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:43 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*maplist;
	t_list	*maplist_iter;
	t_list	*iter;

	if (lst == NULL || f == NULL)
		return (NULL);
	maplist = f(lst);
	maplist_iter = maplist;
	iter = lst->next;
	while (iter != NULL)
	{
		maplist_iter->next = f(iter);
		maplist_iter = maplist_iter->next;
		iter = iter->next;
	}
	return (maplist);
}
