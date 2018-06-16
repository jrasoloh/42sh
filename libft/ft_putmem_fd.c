/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 20:38:14 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:44 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem_fd(void *p, size_t len, int mode, int fd)
{
	size_t			i;
	unsigned char	c;

	i = 0;
	while (i < len)
	{
		c = ((unsigned char*)p)[i];
		if (mode == 0)
		{
			if (ft_numlen_base(c, 16) < 2)
				ft_putchar_fd('0', fd);
			ft_putnbr_base(c, "0123456789ABCDEF");
			if (i + 1 < len)
				ft_putchar(' ');
		}
		else if (mode == 1)
		{
			if (ft_isprint(c) == 1)
				ft_putchar_fd(c, fd);
			else
				ft_putchar_fd('.', fd);
		}
		i++;
	}
}
