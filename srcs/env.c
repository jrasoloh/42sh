/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:17:29 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/12 16:06:19 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

char	**get_env(char **env, char *name)
{
	size_t	name_len;
	int		i;

	name_len = ft_strlen(name);
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], name, name_len) == 0
				&& ft_strchri(env[i], '=') == (int)name_len)
			return (&env[i]);
	}
	return (NULL);
}

char	*get_val(char **env, char *name)
{
	size_t	name_len;
	int		line;
	int		chr;

	line = -1;
	name_len = ft_strlen(name);
	while (env[++line])
	{
		if (ft_strncmp(env[line], name, name_len) == 0
				&& ft_strchri(env[line], '=') == (int)name_len)
		{
			chr = -1;
			while (env[line][++chr])
			{
				if (env[line][chr] == '=')
					return (&env[line][chr + 1]);
			}
		}
	}
	return (NULL);
}

int		set_val(char ***env, char *name, char *val)
{
	char	*f;
	char	**f_split;
	char	*val_dup;

	val_dup = ft_strdup(val);
	f = ft_format("setenv %s %s", name, val_dup);
	f_split = ft_strsplit(f, ' ');
	run_setenv(f_split, env);
	free(val_dup);
	free(f);
	ft_ntsarr_free(&f_split);
	return (0);
}

int		add_room_env(char ***env)
{
	size_t	env_len;
	char	**copy;
	int		i;

	env_len = ft_ntsarr_len(*env) + 1;
	if ((copy = (char**)malloc(sizeof(char*) * (env_len + 1))) == NULL)
		return (0);
	copy[env_len] = 0;
	i = -1;
	while ((*env)[++i])
		copy[i] = (*env)[i];
	free(*env);
	*env = copy;
	return (env_len);
}
