/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_silistnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:39:35 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/06 17:06:29 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_silist	*ft_silistnew(int data)
{
	t_silist	*list;

	if ((list = (t_silist*)ft_memalloc(sizeof(t_silist))) == NULL)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}
