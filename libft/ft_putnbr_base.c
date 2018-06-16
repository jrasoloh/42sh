/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 20:22:15 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:44 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, char *base)
{
	size_t	base_len;
	size_t	nb_len;
	long	div;
	int		neg;

	base_len = ft_strlen(base);
	nb_len = ft_numlen_base(n, base_len);
	div = (nb_len > 1 ? ft_pow(base_len, nb_len - 1) : 1);
	neg = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		neg = -1;
	}
	while (nb_len-- > 0)
	{
		ft_putchar_fd(base[ft_abs(((n / div) % base_len) * neg)], 1);
		div /= base_len;
	}
}
