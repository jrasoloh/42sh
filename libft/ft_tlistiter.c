/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlistiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:49:33 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:20:06 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tlistiter(t_tlist *list, void (*f)(t_token *t))
{
	while (list != NULL)
	{
		f(list->t);
		list = list->next;
	}
}
