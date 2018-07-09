/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlistnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:34:51 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:20:46 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tlist	*ft_tlistnew(t_token *t)
{
	t_tlist	*list;

	if ((list = (t_tlist*)ft_memalloc(sizeof(t_tlist))) == NULL)
		return (NULL);
	list->t = t;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}
