/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twentyonesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 20:43:49 by echojnow          #+#    #+#             */
/*   Updated: 2018/05/22 15:02:29 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

static void	sigint_handler(int sig)
{
	char *pwd;

	FT_UNUSED(sig);
	pwd = save_pwd(NULL);
	ft_putchar('\n');
	ft_put(TO_PROMPT, pwd);
}

static void	clean_input(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '\t')
			input[i] = ' ';
	}
}

static int	loop(char *input, char ***env)
{
	int		running;
	int		gnl_result;
	char	**input_split;
	char	*cpy;

	t_token	**tokens;
	t_bst	*ast;

	running = 1;
	ft_put(TO_PROMPT, save_pwd(NULL));
	gnl_result = ft_gnl(1, &input);
	if (gnl_result == 0 || gnl_result == -1)
		running = 0;
	cpy = input;
	input = ft_strtrim(input);
	free(cpy);
	if (input != NULL && *input != 0 && ft_strisblank(input) == 0)
	{
		clean_input(input);

		tokens = lexe(input);
		ast = parse(tokens);
		interprete(ast, env);

		ft_put("^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		input_split = ft_strsplit(input, ' ');
		/* if (eval(input_split, env) == TO_EXIT) */
		/* 	running = 0; */
		ft_ntsarr_free(&input_split);
	}
	free(input);
	return (running);
}

int			init_terminal()
{
	int				fd;
	struct termios	orig_termios;
	t_caps			caps;

	fd = STDOUT_FILENO;
	if (isatty(STDOUT_FILENO))
		fd = open(ttyname(STDOUT_FILENO), O_RDWR);
	else
		return (ft_err(1, "ft_select: the terminal is not a tty"));

	save_orig_termios(&orig_termios);
	save_caps(&caps);
	save_fd(fd);

	tcgetattr(fd, &orig_termios);
	register_signals();
	init_caps(&caps);

	configure_term();

	edit_loop();

	exit_term();
	return (0);
}

int			main(int argc, char **argv, char **envp)
{
	char	**env;
	char	*input;
	int		running;

	 init_terminal();

	FT_UNUSED(argc);
	FT_UNUSED(argv);
	signal(SIGINT, &sigint_handler);
	if ((env = init(envp)) == NULL)
		return (1);

	input = NULL;
	running = 1;
	while (running)
		running = loop(input, &env);
	ft_ntsarr_free(&env);
	return (0);
}
