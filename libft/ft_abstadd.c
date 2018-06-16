/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:13:03 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 20:44:09 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_abstadd(t_abst *tree, char *data)
{
	if (ft_strcmp(data, tree->data) < 0)
	{
		if (tree->left == NULL)
			tree->left = ft_abstnew(data);
		else
			ft_abstadd(tree->left, data);
	}
	else
	{
		if (tree->right == NULL)
			tree->right = ft_abstnew(data);
		else
			ft_abstadd(tree->right, data);
	}
}
