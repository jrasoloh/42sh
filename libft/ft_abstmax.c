/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abstmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:25:58 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 18:53:22 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_abst	*ft_abstmax(t_abst *tree)
{
	while (tree->right != NULL)
		tree = tree->right;
	return (tree);
}
