/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_silistinsn_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:34:59 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/07 14:35:37 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_silist		*ft_silistinsn_s(t_silist **list, int data,
		int (*cmp)(int d, int d2))
{
	if (*list != NULL)
		return (ft_silistins_s(list, data, cmp));
	if ((*list = ft_silistnew(data)) == NULL)
		return (NULL);
	return (*list);
}
