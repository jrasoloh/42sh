/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstkdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:36:14 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/10 18:06:15 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bstkdel(t_bstk **tree, void (*del)(void **key, void **data))
{
	if (*tree == NULL)
		return ;
	ft_bstkdel(&((*tree)->left), del);
	ft_bstkdel(&((*tree)->right), del);
	del(&((*tree)->key), &((*tree)->data));
	free(*tree);
	*tree = NULL;
}
