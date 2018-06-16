/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:36:14 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/16 16:15:19 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bstdel(t_bst **tree, void (*del)(void **data))
{
	if (*tree == NULL)
		return ;
	ft_bstdel(&((*tree)->left), del);
	ft_bstdel(&((*tree)->right), del);
	del(&((*tree)->data));
	free(*tree);
	*tree = NULL;
}
