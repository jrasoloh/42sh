/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstkaddt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:01:21 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/11 14:11:53 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bstkaddt(t_bstk *tree, t_bstk *to_add, int (*cmp)(void *k, void *k2))
{
	if (cmp(to_add->key, tree->key) < 0)
	{
		if (tree->left == NULL)
			tree->left = to_add;
		else
			ft_bstkaddt(tree->left, to_add, cmp);
	}
	else
	{
		if (tree->right == NULL)
			tree->right = to_add;
		else
			ft_bstkaddt(tree->right, to_add, cmp);
	}
}
