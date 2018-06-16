/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:56:53 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/12 14:13:10 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

static void	simple(char *input, char ***env)
{
	char	*pwd;
	char	*oldpwd;

	pwd = ft_strdup(get_val(*env, "PWD"));
	set_path(&pwd, input);
	if (chdir(pwd) == -1)
		ft_put("21sh: cd: can't access: \"%s\"\n", input);
	else
	{
		if ((oldpwd = get_val(*env, "PWD")) != NULL)
			set_val(env, "OLDPWD", oldpwd);
		set_val(env, "PWD", pwd);
		save_pwd(get_val(*env, "PWD"));
	}
	free(pwd);
}

static int	traverse_link(char *input, char ***env)
{
	char	*cwd;
	char	*oldpwd;

	if (chdir(input) == -1)
		ft_put("21sh: cd: can't access: \"%s\"\n", input[2]);
	else
	{
		if ((cwd = getcwd(NULL, 0)) == NULL)
			return (1);
		if ((oldpwd = get_val(*env, "PWD")) != NULL)
			set_val(env, "OLDPWD", oldpwd);
		set_val(env, "PWD", cwd);
		save_pwd(get_val(*env, "PWD"));
		free(cwd);
	}
	return (0);
}

static int	back(char ***env)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = get_val(*env, "OLDPWD");
	if (oldpwd == NULL)
		return (ft_err(0, "21sh: cd: OLDPWD is not defined"));
	pwd = ft_strdup(get_val(*env, "PWD"));
	if (oldpwd != NULL)
	{
		if (chdir(oldpwd) == -1)
			ft_put("21sh: cd: can't access: \"%s\"\n", oldpwd);
		else
		{
			set_val(env, "PWD", oldpwd);
			if (pwd != NULL)
				set_val(env, "OLDPWD", pwd);
		}
	}
	if (pwd)
		free(pwd);
	return (0);
}

static int	without_dir(char *home, size_t input_len, char **input, char ***env)
{
	if (input_len == 1)
	{
		if (home != NULL)
			simple(home, env);
		else
			ft_put("21sh: cd: HOME is not defined\n");
		return (1);
	}
	else if (ft_strcmp(input[1], "-P") == 0 && input_len == 2)
	{
		if (home != NULL)
			traverse_link(home, env);
		else
			ft_put("21sh: cd: HOME is not defined\n");
		return (1);
	}
	return (0);
}

int			run_cd(char **input, char ***env)
{
	size_t	input_len;
	char	*home;

	input_len = ft_ntsarr_len(input);
	home = NULL;
	home = get_val(*env, "HOME");
	if (without_dir(home, input_len, input, env))
		return (0);
	else if (ft_strcmp(input[1], "-P") == 0 && input_len == 3)
		traverse_link(input[2], env);
	else if (ft_strcmp(input[1], "-") == 0 && input_len == 2)
		back(env);
	else if (input_len == 2)
		simple(input[1], env);
	else
		ft_put("21sh: cd: usage: cd [-P] [dir]\n");
	return (0);
}
