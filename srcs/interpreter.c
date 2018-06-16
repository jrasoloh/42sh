/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noom </var/spool/mail/noom>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:55:48 by noom              #+#    #+#             */
/*   Updated: 2018/06/14 15:42:56 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

char	*pipe_node(t_bst *ast, char ***env)
{
	t_token	*token1;
	t_token	*token2;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*read_buffer;
	int		read_len;

	token1 = (t_token*)ast->left->data;
	token2 = (t_token*)ast->right->data;
	pipe(fd);
	if ((pid1 = fork()) == -1)
		ft_put("WARNING: fork1 went wrong\n");
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		eval2(token1, env);
		exit(0);
	}
	if ((pid2 = fork()) == -1)
		ft_put("WARNING: fork2 went wrong\n");
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		eval2(token1, env);
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);

	wait(&pid1);
	wait(&pid2);

	return (NULL);
}

void	pipe_node2(t_bst *ast, char ***env)
{
	t_token	*token1;
	t_token	*token2;
	int		p[2];
	pid_t	pid;

	int in_cpy = dup(0);
	int out_cpy = dup(1);

	token1 = (t_token*)ast->left->data;
	token2 = (t_token*)ast->right->data;

	ft_put("TOKEN1::::::\n");
	print_token(token1);

	ft_put("TOKEN2::::::\n");
	print_token(token2);

	pipe(p);
	if ((pid = fork()) == -1)
		ft_put("Couldnt fork the process");
	if (pid == 0) // Child process
	{
		close(1);
		close(p[0]);
		dup2(p[1], 1);

		eval2(token1, env);
		exit(0);
	}
	else // Parent process
	{
		wait(&pid);
		close(0);
		close(p[1]);
		dup2(p[0], 0);

		eval2(token2, env);
	}
	close(p[0]);
	close(p[1]);
	dup2(in_cpy, 0);
	dup2(out_cpy, 1);
	close(in_cpy);
	close(out_cpy);
}

void	run(t_bst *ast, char ***env)
{
	static int	in = 0;
	static int	fd[2];
	t_token		*t;

	if (ast == NULL)
	{
		ft_put("AST == NULL, exiting interpreter\n");
		return ;
	}
	ft_put("AST != NULL\n");

	run(ast->left, env);

	t = (t_token*)ast->data;
	if (kind_isop(t->kind))
	{
		if (t->kind == TO_PIPE)
		{
			/* pipe_node2(ast, env); */
			pipe(fd);
			/* fork_proc(in, fd[1], t, env); */
			close(fd[1]);
			in = fd[0];
		}
	}
	/* if (token->kind == TO_GRP || token->kind == TO_CMD) */
	/* { */
	/* 	eval2(token, env); */
	/* } */

	run(ast->right, env);
}

int		fork_proc(int in, int out, t_token *t, char ***env)
{
	pid_t	pid;

	if ((pid = fork()) == -1)
		ft_put("Couldnt fork the process\n");
	else if (pid == 0) // Child
	{
		if (in != 0)
		{
			dup2(in, 0);
			close(in);
		}
		if (out != 1)
		{
			dup2(out, 1);
			close(out);
		}
		eval2(t, env);
		exit(0);
	}
	else // Parent
	{
		/* ft_put("hello\n"); */
		/* wait(&pid); */
	}
	return (pid);
}

void	manage_pipe(t_bst *ast, char ***env)
{
	/* static int	fd[2]; */
	/* static int	in = 0; */
	/* static int	out = 0; */

	static int	first = 1;
	int		fd[2];

	pipe(fd);
	if (first)
	{
		close(fd[1]);
		ft_put("1 running %s\n", ((t_token*)ast->right->data)->value);
		ft_put_fd(fd[0], "hey\n");
		fork_proc(fd[0], 1, (t_token*)ast->right->data, env);
		/* ft_put_fd(fd[1], "hey\n"); */
		first = 0;
	}
	else
	{
		ft_put("2 running %s\n", ((t_token*)ast->right->data)->value);
		fork_proc(fd[0], fd[1], (t_token*)ast->right->data, env);
	}

	if (((t_token*)ast->left->data)->kind == TO_PIPE)
		manage_pipe(ast->left, env);
	else
	{
		close(fd[0]);
		ft_put("3 running %s\n", ((t_token*)ast->left->data)->value);
		fork_proc(0, fd[1], (t_token*)ast->left->data, env);
		first = 1;
	}
}

void	run3(t_bst *ast, char ***env)
{
	// if node is pipe
	//		manage_pipe(ast);

	// _manage_pipe_
	//		execute right, redirecting in, not out
	//	if left is pipe
	//		manage_pipe(ast->left);
	//	else
	//		execute left redirecting in and out
	if (((t_token*)ast->left->data)->kind == TO_PIPE)
		manage_pipe(ast, env);
}

int		interprete(t_bst *ast, char ***env)
{
	run3(ast, env);
	return (0);
}
	/* int     fd[2], nbytes; */
	/* pid_t   childpid; */
	/* char    string[] = "Hello, world!\n"; */
	/* char    readbuffer[1024]; */
	/* char	*argv[2] = { "ls", NULL }; */

	/* pipe(fd); */

	/* if ((childpid = fork()) == -1) */
	/* { */
	/*	ft_put("error\n"); */
	/*	exit(1); */
	/* } */
	/* if (childpid == 0) */
	/* { */
	/*	dup2(fd[1], 1);  // send stdout to the pipe */

	/*	/1* execve("/bin/ls", argv, env); *1/ */
	/* } */
	/* else */
	/* { */
	/*	/1* Parent process closes up output side of pipe *1/ */
	/*	close(fd[1]); */

	/*	/1* Read in a string from the pipe *1/ */
	/*	nbytes = read(fd[0], readbuffer, sizeof(readbuffer)); */
	/*	readbuffer[nbytes] = '\0'; */
	/*	ft_put("Received string: '%s'", readbuffer); */
	/* } */
	/* return (0); */
/* } */

void	run2(t_bst *ast, char ***env)
{
	static int	iter_nb = 0;
	static int	in = 0;
	static int	fd[2];

	if (((t_token*)ast->left->data)->kind == TO_PIPE)
	{
		iter_nb++;
		run2(ast->left, env);
	}

	if (((t_token*)ast->left->data)->kind == TO_GRP)
	{
		ft_put("FIRST =============================\n");
		pipe(fd);
		fork_proc(in, fd[1], (t_token*)ast->left->data, env);
		close(fd[1]);
		in = fd[0];
	}

	if (iter_nb != 0)
	{
		ft_put("SECOND =============================\n");
		pipe(fd);
		fork_proc(in, fd[1], (t_token*)ast->right->data, env);
		close(fd[1]);
		in = fd[0];
	}
	else
	{
		if (in != 0)
			dup2(in, 0);
		ft_put("THIRD =============================\n");
		eval2((t_token*)ast->right->data, env);
	}
	ft_put("iter_nb = %d\n", iter_nb);
	iter_nb--;
}

