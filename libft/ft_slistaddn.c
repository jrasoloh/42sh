/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slistaddn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:19:51 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/06 14:24:12 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist	*ft_slistaddn(t_slist **list, void *data)
{
	if (*list != NULL)
		return (ft_slistadd(list, data));
	if ((*list = ft_slistnew(data)) == NULL)
		return (NULL);
	return (*list);
}
