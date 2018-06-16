/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slistiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:12:28 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/06 15:00:49 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_slistiter(t_slist *list, void (*f)(void *data))
{
	while (list != NULL)
	{
		f(list->data);
		list = list->next;
	}
}
