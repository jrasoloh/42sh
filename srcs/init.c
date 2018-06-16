/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:22:12 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/12 16:13:26 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

static char	**copy_envp(char **envp)
{
	int		len;
	char	**env;
	int		i;

	len = ft_ntsarr_len(envp);
	if ((env = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
		return (NULL);
	env[len] = 0;
	i = -1;
	while (++i < len)
		env[i] = ft_strdup(envp[i]);
	return (env);
}

static int	incr_shlvl(char ***env)
{
	char	*shlvl;
	char	*value;

	if ((shlvl = get_val(*env, "SHLVL")) == NULL)
		return (TO_ERROR);
	value = ft_itoa(ft_atoi(shlvl) + 1);
	set_val(env, "SHLVL", value);
	free(value);
	return (0);
}

char		**init(char **envp)
{
	char	**env;
	char	*cwd;

	if ((env = copy_envp(envp)) == NULL)
		return (NULL);
	incr_shlvl(&env);
	if (get_val(env, "PWD") == NULL)
	{
		if ((cwd = getcwd(NULL, 0)) != NULL)
		{
			set_val(&env, "PWD", cwd);
			free(cwd);
		}
	}
	save_pwd(get_val(env, "PWD"));
	return (env);
}
