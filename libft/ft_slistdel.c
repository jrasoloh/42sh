/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slistdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:35:21 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/01 15:45:32 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_slistdel(t_slist **list, void (*del)(void **data))
{
	t_slist	*iter;
	t_slist	*tmp;

	iter = *list;
	while (iter != NULL)
	{
		tmp = iter->next;
		del(&(iter->data));
		free(iter);
		iter = tmp;
	}
	*list = NULL;
}
