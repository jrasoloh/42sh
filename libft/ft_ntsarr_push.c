/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntsarr_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:23:11 by echojnow          #+#    #+#             */
/*   Updated: 2018/05/12 13:37:49 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_ntsarr_push(char ***ntsarr, char *s)
{
	size_t	len;
	char	**new;
	int		i;

	len = ft_ntsarr_len(*ntsarr);
	if ((new = (char**)malloc(sizeof(char*) * (len + 2))) == NULL)
		return (NULL);
	new[len + 1] = NULL;
	new[0] = ft_strdup(s);
	i = -1;
	while ((*ntsarr)[++i])
		new[i + 1] = (*ntsarr)[i];
	free(*ntsarr);
	*ntsarr = new;
	return (new);
}
