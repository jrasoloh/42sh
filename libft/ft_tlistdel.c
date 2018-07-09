/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlistdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:50:28 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:19:41 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tlistdel(t_tlist **list)
{
	t_tlist	*iter;
	t_tlist	*tmp;
	int i;

	iter = *list;
	i = -1;
	while (iter != NULL)
	{
		tmp = iter->next;
		while (iter->t->args[++i] != '\0')
			free(iter->t->args[i]);
		free(iter->t->args);
		free(iter->t->value);
		free(iter->t);
		free(iter);
		iter = tmp;
	}
	*list = NULL;
}
