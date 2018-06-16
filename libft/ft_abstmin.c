/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abstmin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:26:00 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 18:53:25 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_abst	*ft_abstmin(t_abst *tree)
{
	while (tree->left != NULL)
		tree = tree->left;
	return (tree);
}
