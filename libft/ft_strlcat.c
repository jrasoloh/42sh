/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:16:14 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:45 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t dst_i;
	size_t src_i;

	dst_len = ft_strlen(dst);
	dst_i = ft_strlen(dst);
	src_i = 0;
	if (size < dst_len)
		return (size + ft_strlen(src));
	while (dst_i < size - 1 && src[src_i])
	{
		dst[dst_i] = src[src_i];
		dst_i++;
		src_i++;
	}
	dst[dst_i] = '\0';
	return (dst_len + ft_strlen(src));
}
