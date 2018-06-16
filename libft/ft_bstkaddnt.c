/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstkaddnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:01:47 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/11 14:10:21 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bstk	*ft_bstkaddnt(t_bstk **tree, t_bstk *to_add, int (*cmp)(void *k,
			void *k2))
{
	if (*tree == NULL)
	{
		if ((*tree = to_add) == NULL)
			return (NULL);
		return (*tree);
	}
	if (cmp(to_add->key, (*tree)->key) < 0)
	{
		if ((*tree)->left == NULL)
			(*tree)->left = to_add;
		else
			ft_bstkaddt((*tree)->left, to_add, cmp);
	}
	else
	{
		if ((*tree)->right == NULL)
			(*tree)->right = to_add;
		else
			ft_bstkaddt((*tree)->right, to_add, cmp);
	}
	return (*tree);
}
