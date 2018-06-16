/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstknew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:34:12 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/10 18:08:52 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bstk	*ft_bstknew(void *key, void *data)
{
	t_bstk *tree;

	if ((tree = (t_bstk*)ft_memalloc(sizeof(t_bstk))) == NULL)
		return (NULL);
	tree->key = key;
	tree->data = data;
	tree->right = NULL;
	tree->left = NULL;
	return (tree);
}
