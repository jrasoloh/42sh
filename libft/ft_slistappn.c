/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slistappn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:31:44 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/06 15:00:57 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist	*ft_slistappn(t_slist **list, void *data)
{
	if (*list != NULL)
		return (ft_slistapp(*list, data));
	if ((*list = ft_slistnew(data)) == NULL)
		return (NULL);
	return (*list);
}
