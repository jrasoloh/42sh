/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abstaddn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 20:45:16 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 21:28:46 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_abst	*ft_abstaddn(t_abst **tree, char *data)
{
	if (*tree == NULL)
	{
		if ((*tree = ft_abstnew(data)) == NULL)
			return (NULL);
		return (*tree);
	}
	if (ft_strcmp(data, (*tree)->data) < 0)
	{
		if ((*tree)->left == NULL)
			(*tree)->left = ft_abstnew(data);
		else
			ft_abstadd((*tree)->left, data);
	}
	else
	{
		if ((*tree)->right == NULL)
			(*tree)->right = ft_abstnew(data);
		else
			ft_abstadd((*tree)->right, data);
	}
	return (*tree);
}
