/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:05:50 by echojnow          #+#    #+#             */
/*   Updated: 2018/05/15 19:05:14 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

static int	test_access(char *path)
{
	char	*err;
	char	*basename;

	err = NULL;
	if ((basename = ft_basename(path)) == NULL)
		return (TO_ERROR);
	if (ft_file_exists(path) == 0)
		ft_format("21sh: %s: file not found", basename);
	else if (access(path, X_OK) == -1)
		err = ft_format("21sh: %s: permission denied", basename);
	if (err)
	{
		ft_putendl(err);
		free(err);
		free(basename);
		return (1);
	}
	free(basename);
	return (0);
}

static char	*bin_path(char **env, char *bin)
{
	char	*val;
	char	**path_split;
	char	*cur_path;
	int		i;

	if ((val = get_val(env, "PATH")) == NULL)
		return (NULL);
	path_split = ft_strsplit(val, ':');
	i = -1;
	while (path_split[++i])
	{
		cur_path = ft_pathjoin(path_split[i], bin);
		if (ft_file_exists(cur_path) == 1)
		{
			ft_ntsarr_free(&path_split);
			return (cur_path);
		}
		free(cur_path);
	}
	ft_ntsarr_free(&path_split);
	return (NULL);
}

static int	run_builtin(t_token *t, char ***env)
{
	if (ft_strcmp(t->value, "echo") == 0)
		run_echo(t->args);
	else if (ft_strcmp(t->value, "cd") == 0)
		run_cd(t->args, env);
	else if (ft_strcmp(t->value, "env") == 0)
		run_env(*env);
	else if (ft_strcmp(t->value, "setenv") == 0)
	{
		if (ft_ntsarr_len(t->args) == 1)
			run_env(*env);
		else
			run_setenv(t->args, env);
	}
	else if (ft_strcmp(t->value, "unsetenv") == 0)
		run_unsetenv(t->args, env);
	else if (ft_strcmp(t->value, "exit") == 0)
		return (TO_EXIT);
	else
		return (0);
	return (1);
}

static int	run_bin(char *bin, char **argv, char **env)
{
	pid_t	pid;

	if (argv != NULL)
		ft_ntsarr_push(&argv, bin);
	else
	{
		argv = (char**)malloc(sizeof(char*) * 2);
		argv[0] = ft_strdup(bin);
		argv[1] = NULL;
	}
	ft_put("RUNNING BIN %s \n", bin);
	/* ft_put("--- print argv ---\n"); */
	/* ft_ntsarr_print(argv, 1); */
	/* ft_put("--- end of argv ---\n"); */

	if ((pid = fork()) == -1)
		return (-1);
	else if (pid > 0)
		wait(&pid);
	else if (pid == 0)
		execve(bin, argv, env);
	return (0);
}

int			eval2(t_token *t, char ***env)
{
	int		bi;
	char	*bin;

	/* update_input(input, *env); */
	if ((bi = run_builtin(t, env)) > 0)
	{
		if (bi == TO_EXIT)
			return (TO_EXIT);
	}
	else if ((bin = bin_path(*env, t->value)) != NULL)
	{
		if (test_access(bin) == 0
				&& run_bin(bin, t->args, *env) == -1)
			return (1);
		free(bin);
	}
	return (0);
}

int			eval(char **input, char ***env)
{
	int		bi;
	char	*bin;

	update_input(input, *env);
	if ((bi = run_builtin(input, env)) > 0)
	{
		if (bi == TO_EXIT)
			return (TO_EXIT);
	}
	else if (ft_strchr(input[0], '/') != NULL)
	{
		if (test_access(input[0]) == 0
				&& run_bin(input[0], input, *env) == -1)
			return (1);
	}
	else if ((bin = bin_path(*env, input[0])) != NULL)
	{
		if (test_access(bin) == 0
				&& run_bin(bin, input, *env) == -1)
			return (1);
		free(bin);
	}
	else
		ft_put("21sh: %s: command not found\n", input[0]);
	return (0);
}
