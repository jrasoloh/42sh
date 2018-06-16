/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:43:02 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:43 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if ((mem = malloc(size)) == NULL)
		return (NULL);
	while (size-- > 0)
	{
		((char*)mem)[size] = 0;
	}
	return (mem);
}
