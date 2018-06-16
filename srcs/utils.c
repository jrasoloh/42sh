/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:21:16 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/12 16:07:38 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

int		is_envname_equal(char *input, char *full)
{
	if (ft_strncmp(input, full, ft_strlen(input)) == 0
			&& ft_strchri(full, '=') == (int)ft_strlen(input))
		return (1);
	return (0);
}

int		check_unsetenv(char **input, char **env)
{
	if (ft_ntsarr_len(input) != 2)
		return (ft_err(1, "21sh: unsetenv: usage: unsetenv [NAME]"));
	if (get_val(env, input[1]) == NULL)
		return (ft_err(1, "21sh: unsetenv: no such variable found"));
	if (ft_strcmp(input[1], "PWD") == 0)
		return (ft_err(1, TO_2001));
	return (0);
}

char	*save_pwd(char *pwd)
{
	static char	*saved;

	if (pwd != NULL)
		saved = pwd;
	return (saved);
}

void	new_path(char **path, char **to_split)
{
	int		i;
	char	*cpy;
	int		sla_i;

	i = -1;
	while (to_split[++i])
	{
		cpy = NULL;
		if (ft_strcmp(to_split[i], "..") == 0)
		{
			sla_i = ft_strrchri(*path, '/');
			cpy = ft_strsub(*path, 0, (sla_i == 0 ? sla_i++ : sla_i));
		}
		else if (ft_strcmp(to_split[i], ".") != 0)
			cpy = ft_pathjoin(*path, to_split[i]);
		if (cpy != NULL)
		{
			free(*path);
			*path = cpy;
		}
	}
}

void	set_path(char **path, char *to)
{
	char	**to_split;

	if (to[0] == '/')
	{
		free(*path);
		*path = ft_strdup(to);
	}
	else
	{
		to_split = ft_strsplit(to, '/');
		new_path(path, to_split);
		ft_ntsarr_free(&to_split);
		if (ft_strcmp(*path, "") == 0)
		{
			free(*path);
			*path = ft_strdup("/");
		}
	}
}
