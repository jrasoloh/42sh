/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slistinsn_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:28:51 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/24 16:35:48 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist		*ft_slistinsn_s(t_slist **list, void *data,
		int (*cmp)(void *d, void *d2))
{
	if (*list != NULL)
		return (ft_slistins_s(list, data, cmp));
	if ((*list = ft_slistnew(data)) == NULL)
		return (NULL);
	return (*list);
}
