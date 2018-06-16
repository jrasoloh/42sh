/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:58:40 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/26 14:56:49 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_throw(const char *name, const char *err_message,
		char *err_value, int err_return)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err_value, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err_message, 2);
	return (err_return);
}
