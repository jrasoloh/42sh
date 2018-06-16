/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstkmin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:36:05 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/08 12:37:07 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bstk	*ft_bstkmin(t_bstk *tree)
{
	while (tree->left != NULL)
		tree = tree->left;
	return (tree);
}
