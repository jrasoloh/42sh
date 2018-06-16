/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:38:26 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/16 16:13:13 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bstadd(t_bst *tree, void *data, int (*cmp)(void *d, void *d2))
{
	if (cmp(data, tree->data) < 0)
	{
		if (tree->left == NULL)
			tree->left = ft_bstnew(data);
		else
			ft_bstadd(tree->left, data, cmp);
	}
	else
	{
		if (tree->right == NULL)
			tree->right = ft_bstnew(data);
		else
			ft_bstadd(tree->right, data, cmp);
	}
}
