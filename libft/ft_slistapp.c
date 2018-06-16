/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slistapp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:05:11 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/06 13:18:13 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist	*ft_slistapp(t_slist *list, void *data)
{
	t_slist	*new;

	if ((new = ft_slistnew(data)) == NULL)
		return (NULL);
	ft_slistlast(list)->next = new;
	return (new);
}
