/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:49:57 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:43 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen_base(int n, int base)
{
	long	div;
	int		len;

	if (n == 0)
		return (1);
	div = 1;
	len = 0;
	while (n / div != 0)
	{
		div *= base;
		len++;
	}
	div /= base;
	return (len);
}
