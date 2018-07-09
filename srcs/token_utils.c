/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:29:06 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 15:01:19 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

size_t		ntarr_len(t_token **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

int			is_cpartofw(char c)
{
	return (ft_isalnum(c) || c == '-' || c == '-' || c == '~' || c == '!');
}

void		print_token(t_token *t)
{
	int	arg_i;

	ft_put("kind: %s(%d), value: '%s'\n", kind_tostr(t->kind), t->kind, t->value);
	if (t->kind == TO_GRP)
	{
		arg_i = -1;
		while (t->args[++arg_i] != '\0')
			ft_put("arg_i: %d -> '%s'\n", arg_i, t->args[arg_i]);
	}
}

/* void		print_tokens(t_token **tokens) */
/* { */
/* 	int	i; */
/* 	int arg_i; */

/* 	i = -1; */
/* 	while (tokens[++i]) */
/* 	{ */
/* 		print_token(tokens[i]); */
/* 		if (tokens[i]->kind == TO_GRP) */
/* 		{ */
/* 			arg_i = -1; */
/* 			while (tokens[i]->args[++arg_i]) */
/* 				ft_put("t_i: %d, arg_i: %d -> '%s'\n", i, arg_i, tokens[i]->args[arg_i]); */
/* 		} */
/* 	} */
/* } */

void		print_tokens(t_tlist *tokens)
{
	t_tlist	*iter;
	int		arg_i;

	iter = tokens;
	while (iter != NULL)
	{
		print_token(iter->t);
		if (iter->t->kind == TO_GRP)
		{
			arg_i = -1;
			while (iter->t->args[++arg_i])
				ft_put("arg_i: %d -> '%s'\n", arg_i, iter->t->args[arg_i]);
		}
		iter = iter->next;
	}
}

int		next_nonblank(char *s, int start)
{
	while (s[start++])
	{
		if (s[start] != ' ' && s[start] != '\t')
			return (start);
	}
	return (start);
}

char	*kind_tostr(int kind)
{
	if (kind == TO_UK)
		return ("UNKNOWN");
	if (kind == TO_WORD)
		return ("WORD");
	if (kind == TO_OP)
		return ("OPERATOR");
	if (kind == TO_CMD)
		return ("COMMAND");
	if (kind == TO_ARG)
		return ("ARGUMENT");
	if (kind == TO_GRP)
		return ("GROUP");
	if (kind == TO_PIPE)
		return ("PIPE");
	if (kind == TO_REDIR)
		return ("REDIRECTION");
	if (kind == TO_FILE)
		return ("FILE");
	else
		return ("0000");

	/* if (kind == TO_UK) */
	/* 	return ("ukwn"); */
	/* if (kind == TO_WORD) */
	/* 	return ("word"); */
	/* if (kind == TO_OP) */
	/* 	return ("oper"); */
	/* if (kind == TO_CMD) */
	/* 	return ("comd"); */
	/* if (kind == TO_ARG) */
	/* 	return ("argu"); */
	/* if (kind == TO_GRP) */
	/* 	return ("grpe"); */
	/* if (kind == TO_PIPE) */
	/* 	return ("pipe"); */
	/* if (kind == TO_REDIR) */
	/* 	return ("rdir"); */
	/* if (kind == TO_FILE) */
	/* 	return ("file"); */
	/* else */
	/* 	return ("0000"); */
}

int		kind_isop(int kind)
{
	if (kind == TO_OP
			|| kind == TO_PIPE
			|| kind == TO_REDIR)
		return (1);
	return (0);
}
