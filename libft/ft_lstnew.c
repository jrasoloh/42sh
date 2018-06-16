/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:47:40 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:43 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	void	*newcontent;
	t_list	*list;

	if (content == NULL)
	{
		content_size = 0;
		newcontent = NULL;
	}
	else
	{
		if ((newcontent = ft_memalloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(newcontent, content, content_size);
	}
	if ((list = (t_list*)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = newcontent;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
