/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:15:45 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/09 16:03:21 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_abstdel(t_abst **tree)
{
	if (*tree == NULL)
		return ;
	ft_abstdel(&((*tree)->right));
	ft_abstdel(&((*tree)->left));
	ft_strdel(&((*tree)->data));
	free(*tree);
	*tree = NULL;
}
