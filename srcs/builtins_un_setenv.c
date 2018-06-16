/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_un_setenv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:10:36 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/12 16:04:15 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

static int	env_name_isok(char **input)
{
	int	i;

	if (ft_ntsarr_len(input) < 2)
		return (0);
	i = -1;
	while (input[1][++i])
	{
		if ((input[1][i] <= ' ')
				|| (!(input[1][i] >= 'a' && input[1][i] <= 'z')
					&& !(input[1][i] >= 'A' && input[1][i] <= 'Z')
					&& !(input[1][i] == '_')))
			return (0);
	}
	return (1);
}

int			run_setenv(char **input, char ***env)
{
	size_t	var_len;
	int		new_len;
	char	**env_var;

	if (env_name_isok(input) == 0 || ft_ntsarr_len(input) < 3)
		return (ft_err(0, "21sh: setenv: usage: setenv [NAME] [VALUE]"));
	var_len = ft_strlen(input[1]);
	if ((env_var = get_env(*env, input[1])) != NULL)
	{
		free(*env_var);
		*env_var = ft_format("%s=%s", input[1], input[2]);
	}
	else
	{
		if ((new_len = add_room_env(env)) == 0)
			return (TO_ERROR);
		(*env)[new_len - 1] = ft_format("%s=%s", input[1], input[2]);
	}
	if (ft_strcmp(input[1], "PWD") == 0)
		save_pwd(get_val(*env, "PWD"));
	return (0);
}

int			run_unsetenv(char **input, char ***env)
{
	size_t	env_len;
	char	**copy;
	int		ei;
	int		ci;

	if (check_unsetenv(input, *env))
		return (0);
	env_len = ft_ntsarr_len(*env) - 1;
	if ((copy = (char**)malloc(sizeof(char*) * (env_len + 1))) == NULL)
		return (1);
	copy[env_len] = NULL;
	ei = -1;
	ci = 0;
	while ((*env)[++ei])
	{
		if (is_envname_equal(input[1], (*env)[ei]))
			free((*env)[ei]);
		else
			copy[ci++] = (*env)[ei];
	}
	free(*env);
	*env = copy;
	return (0);
}
