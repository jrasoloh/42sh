/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstaddn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:40:17 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/16 16:14:08 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bst	*ft_bstaddn(t_bst **tree, void *data, int (*cmp)(void *d,
			void *d2))
{
	if (*tree == NULL)
	{
		if ((*tree = ft_bstnew(data)) == NULL)
			return (NULL);
		return (*tree);
	}
	if (cmp(data, (*tree)->data) < 0)
	{
		if ((*tree)->left == NULL)
			(*tree)->left = ft_bstnew(data);
		else
			ft_bstadd((*tree)->left, data, cmp);
	}
	else
	{
		if ((*tree)->right == NULL)
			(*tree)->right = ft_bstnew(data);
		else
			ft_bstadd((*tree)->right, data, cmp);
	}
	return (*tree);
}
