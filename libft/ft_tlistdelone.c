/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlistdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:50:28 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:19:41 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tlistdelone(t_tlist **list)
{
	t_tlist	*prev;
	t_tlist	*next;
	int i;

	prev = (*list)->prev;
	next = (*list)->next;
	i = -1;
	if ((*list)->t->args != NULL)
	{
		while ((*list)->t->args[++i] != '\0')
			free((*list)->t->args[i]);
	}
	free((*list)->t->args);
	free((*list)->t->value);
	free((*list)->t);
	free(*list);
	*list = next;
	if (*list != NULL)
		(*list)->prev = prev;
	if (prev != NULL)
		prev->next = *list;
}
