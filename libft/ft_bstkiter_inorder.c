/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstkiter_inorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:42:48 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/10 18:03:26 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bstkiter_inorder(t_bstk *tree, void (*f)(void *key, void *data))
{
	if (tree == NULL)
		return ;
	ft_bstkiter_inorder(tree->left, f);
	f(tree->key, tree->data);
	ft_bstkiter_inorder(tree->right, f);
}
