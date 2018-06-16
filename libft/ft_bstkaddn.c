/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstkaddn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:40:17 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/11 14:06:58 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bstk	*ft_bstkaddn(t_bstk **tree, void *key, void *data, int (*cmp)(void *k,
			void *k2))
{
	if (*tree == NULL)
	{
		if ((*tree = ft_bstknew(key, data)) == NULL)
			return (NULL);
		return (*tree);
	}
	if (cmp(key, (*tree)->key) < 0)
	{
		if ((*tree)->left == NULL)
			(*tree)->left = ft_bstknew(key, data);
		else
			ft_bstkadd((*tree)->left, key, data, cmp);
	}
	else
	{
		if ((*tree)->right == NULL)
			(*tree)->right = ft_bstknew(key, data);
		else
			ft_bstkadd((*tree)->right, key, data, cmp);
	}
	return (*tree);
}
