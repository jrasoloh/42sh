/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abstiter_inorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 20:09:07 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/09 15:23:30 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_abstiter_inorder(t_abst *tree, void (*f)(char *data))
{
	if (tree == NULL)
		return ;
	ft_abstiter_inorder(tree->left, f);
	f(tree->data);
	ft_abstiter_inorder(tree->right, f);
}
