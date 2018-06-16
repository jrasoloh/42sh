/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:06:55 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:42 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_len(int n)
{
	long	div;
	int		len;

	if (n == 0)
		return (1);
	div = 1;
	len = 0;
	while (n / div != 0)
	{
		div *= 10;
		len++;
	}
	div /= 10;
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	long	div;
	size_t	i;
	int		neg;
	char	*str;

	len = number_len(n);
	div = (len > 1 ? ft_pow(10, len - 1) : 1);
	i = 0;
	neg = 1;
	if ((str = (char*)malloc(sizeof(char) * (n < 0 ? ++len : len) + 1)) == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		neg = -1;
	}
	str[len] = '\0';
	while (i < len)
	{
		str[i++] = ft_abs(((n / div) % 10) + (48 * neg));
		div /= 10;
	}
	return (str);
}
