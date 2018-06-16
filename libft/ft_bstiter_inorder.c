/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstiter_inorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:42:48 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/16 16:16:14 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bstiter_inorder(t_bst *tree, void (*f)(void *data))
{
	if (tree == NULL)
		return ;
	ft_bstiter_inorder(tree->left, f);
	f(tree->data);
	ft_bstiter_inorder(tree->right, f);
}
