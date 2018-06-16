/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twentyonesh.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 20:43:47 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/15 15:48:31 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWENTYONESH_H
# define TWENTYONESH_H

# include "libft.h"
# include "line_edition.h"

# include <unistd.h>
# include <sys/types.h>
# include <string.h>
# include <signal.h>
# include <errno.h>

# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <fcntl.h>

# define TO_EXIT 2
# define TO_ERROR 3
# define TO_PROMPT "\e[38;2;200;90;240m%s\e[38;2;190;160;170m>\e[0m "
# define TO_2001 "21sh: unsetenv: I'm afraid I cannot let you do that"

/* # define TO_TOKEN 0 */
/* # define TO_WORD 1 */
/* # define TO_STRING 2 */
/* # define TO_REDIR 3 */
/* # define TO_PIPE 4 */

# define TO_UK -1

# define TO_WORD 0
# define TO_OP 1

# define TO_CMD 2
# define TO_ARG 3
# define TO_GRP 4
# define TO_PIPE 5
# define TO_REDIR 6
# define TO_FILE 7

# define TO_READ_SIZE 1
# define TO_K_ESC '\e'
# define TO_K_DEL 127
# define TO_K_BAC 126
# define TO_K_RET 10
# define TO_K_SPA ' '

typedef struct	s_token
{
	int		kind;
	char	*value;
	char	**args;
}				t_token;

typedef struct	s_op
{
	int		kind;
	t_token	*op1;
	t_token	*op2;
}				t_op;

/*
** init.c
*/
char			**init(char **envp);

/*
** manage_term.c
*/
int				init_caps(t_caps *caps);
struct termios	*save_orig_termios(struct termios *orig_termios);
t_caps			*save_caps(t_caps *caps);
int				save_fd(int fd);
void			configure_term(void);
void			restore_term(void);
void			exit_term();
int				get_winsize(int *width, int *height);

/*
** sighandlers.c
*/
void			register_signals(void);

/*
** eval.c
*/
int				eval(char **input, char ***env);
int				eval2(t_token *t, char ***env);

/*
** interpreter.c
*/
int				interprete(t_bst *ast, char ***env);

/*
** lexer.c
*/
t_token			**lexe(char *input);

/*
** lexer_make_tgs.c
*/
void			make_token_groups(t_token ***tokens);

/*
** parser.c
*/
t_bst			*parse(t_token **tokens);

/*
** token_utils.c
*/
size_t			ntarr_len(t_token **tokens);
void			print_token(t_token *t);
void			print_tokens(t_token **tokens);
int				is_cpartofw(char c);
int				next_nonblank(char *s, int start);
char			*kind_tostr(int kind);
int				kind_isop(int kind);

/*
** update_input.c
*/
void			update_input(char **input, char **env);

/*
** builtins.c
*/
void			run_echo(char **input);
void			run_env(char **env);
int				run_setenv(char **input, char ***env);
int				run_unsetenv(char **input, char ***env);

/*
** builtins_un_setenv.c
*/

/*
** builtins_cd.c
*/
int				run_cd(char **input, char ***env);

/*
** env.c
*/
char			**get_env(char **env, char *name);
char			*get_val(char **env, char *name);
int				set_val(char ***env, char *name, char *val);
int				add_room_env(char ***env);

/*
** utils.c
*/
int				check_unsetenv(char **input, char **env);
int				is_envname_equal(char *input, char *full);
char			*save_pwd(char *pwd);
void			new_path(char **path, char **to_split);
void			set_path(char **path, char *to);

#endif
