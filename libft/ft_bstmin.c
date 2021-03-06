/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:36:05 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/16 16:16:54 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bst	*ft_bstmin(t_bst *tree)
{
	while (tree->left != NULL)
		tree = tree->left;
	return (tree);
}
