/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slistnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:53:12 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/06 13:02:48 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist	*ft_slistnew(void *data)
{
	t_slist	*list;

	if ((list = (t_slist*)ft_memalloc(sizeof(t_slist))) == NULL)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}
