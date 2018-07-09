/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlistadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:47:26 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:17:15 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tlist	*ft_tlistadd(t_tlist **list, t_token *t)
{
	t_tlist	*new;

	if ((new = ft_tlistnew(t)) == NULL)
		return (NULL);
	new->prev = NULL;
	new->next = *list;
	*list = new;
	return (*list);
}
