/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:34:12 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/16 17:28:53 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bst	*ft_bstnew(void *data)
{
	t_bst *tree;

	if ((tree = (t_bst*)ft_memalloc(sizeof(t_bst))) == NULL)
		return (NULL);
	tree->data = data;
	tree->right = NULL;
	tree->left = NULL;
	return (tree);
}
