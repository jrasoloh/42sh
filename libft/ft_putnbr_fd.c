/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:09:55 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:44 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	long	div;
	int		neg;

	len = ft_numlen(n);
	div = (len > 1 ? ft_pow(10, len - 1) : 1);
	neg = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		neg = -1;
	}
	while (len-- > 0)
	{
		ft_putchar_fd(ft_abs(((n / div) % 10) + (48 * neg)), fd);
		div /= 10;
	}
}
