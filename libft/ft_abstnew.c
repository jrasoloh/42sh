/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:15:53 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/06 14:11:46 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_abst	*ft_abstnew(char *data)
{
	t_abst *tree;

	if ((tree = (t_abst*)ft_memalloc(sizeof(t_abst))) == NULL)
		return (NULL);
	tree->right = NULL;
	tree->left = NULL;
	tree->data = data;
	return (tree);
}
