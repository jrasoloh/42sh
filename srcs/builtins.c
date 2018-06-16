/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:45:34 by echojnow          #+#    #+#             */
/*   Updated: 2018/04/26 18:50:43 by noom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void		run_echo(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		ft_put("%s ", input[i++]);
	ft_putchar('\n');
}

void		run_env(char **env)
{
	while (*env)
		ft_putendl(*(env++));
}
