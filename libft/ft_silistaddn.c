/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_silistaddn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:46:16 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/01 15:46:41 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_silist	*ft_silistaddn(t_silist **list, int data)
{
	if (*list != NULL)
		return (ft_silistadd(list, data));
	if ((*list = ft_silistnew(data)) == NULL)
		return (NULL);
	return (*list);
}
