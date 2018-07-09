/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlistapp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:42:07 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:18:41 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tlist	*ft_tlistapp(t_tlist *list, t_token *t)
{
	t_tlist	*new;
	t_tlist	*last;

	if ((new = ft_tlistnew(t)) == NULL)
		return (NULL);
	last = ft_tlistlast(list);
	new->prev = last;
	last->next = new;
	return (new);
}
