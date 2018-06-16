/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstkmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:37:38 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/08 12:37:41 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bstk	*ft_bstkmax(t_bstk *tree)
{
	while (tree->right != NULL)
		tree = tree->right;
	return (tree);
}
