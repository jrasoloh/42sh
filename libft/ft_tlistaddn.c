/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlistaddn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:48:27 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:17:49 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tlist	*ft_tlistaddn(t_tlist **list, t_token *t)
{
	if (*list != NULL)
		return (ft_tlistadd(list, t));
	if ((*list = ft_tlistnew(t)) == NULL)
		return (NULL);
	return (*list);
}
