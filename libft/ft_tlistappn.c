/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlistappn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:37:48 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:19:07 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tlist	*ft_tlistappn(t_tlist **list, t_token *t)
{
	if (*list != NULL)
		return (ft_tlistapp(*list, t));
	if ((*list = ft_tlistnew(t)) == NULL)
		return (NULL);
	return (*list);
}
