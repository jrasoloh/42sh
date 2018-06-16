/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_silistadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:40:38 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/01 15:43:17 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_silist	*ft_silistadd(t_silist **list, int data)
{
	t_silist	*new;

	if ((new = ft_silistnew(data)) == NULL)
		return (NULL);
	new->next = *list;
	*list = new;
	return (*list);
}
