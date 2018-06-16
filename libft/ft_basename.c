/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:13:07 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/25 14:53:43 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_basename(char *path)
{
	int	i;

	i = ft_strrchri(path, '/');
	if (i == -1)
		return (ft_strdup(path));
	return (ft_strsub(path, i + 1, ft_strlen(path) - (i + 1)));
}
