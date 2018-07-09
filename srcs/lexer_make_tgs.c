/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_make_tgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:28:46 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 17:42:04 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

static int	calculate_args_len(t_tlist *start, t_tlist *end)
{
	int	len;

	len = 0;
	while (start != end && start != NULL)
	{
		start = start->next;
		len++;
	}
	return (len);
}

static void	make_token_group(t_tlist *start, t_tlist *end)
{
	ft_put("/ MAKE_TOKEN_GROUP \\\n");
	int		args_len;
	t_tlist	*token;
	int		i;

	args_len = calculate_args_len(start, end);
	ft_put("args_len: %d\n", args_len);
	token = start->prev;
	token->t->kind = TO_GRP;
	token->t->args = (char**)malloc(sizeof(char*) * (args_len + 1));
	token->t->args[args_len] = NULL;
	/* ft_put("args len %d\n", ft_ntsarr_len((*tokens)[start]->args)); */
	/* ft_put("tokens len %d\n", ntarr_len(*tokens)); */
	i = 0;
	while (start != end && start != NULL)
	{
		token->t->args[i] = ft_strdup(start->t->value);

		ft_put("BUILDING TG -> %d, %s\n", i, token->t->args[i]);

		ft_tlistdelone(&start);
		i++;
	}
	ft_put("\\ MAKE_TOKEN_GROUP /\n");
}

static void	make_cmd(t_tlist *tokens)
{
	t_tlist	*iter;

	iter = tokens;
	while (iter != NULL)
	{
		if (iter->prev != NULL && iter->t->kind == TO_WORD)
		{
			if (iter->prev->t->kind == TO_REDIR)
				iter->t->kind = TO_FILE;
			else
				iter->t->kind = TO_CMD;
		}
		else if (iter->prev == NULL && iter->t->kind == TO_WORD)
				iter->t->kind = TO_CMD;
		iter = iter->next;
	}
}

void		make_token_groups(t_tlist **tokens)
{
	size_t		tokens_len;
	t_tlist		*i;
	t_tlist		*j;

	tokens_len = ft_tlistlen(*tokens);
	/* int kind2 = (*tokens)->prev->t->kind; */
	i = *tokens;
	while (i != NULL)
	{
		if (i->prev != NULL && i->prev->t->kind == TO_WORD && i->t->kind == TO_WORD)
		{
			ft_put("current token: %d, '%s'\n", i->t->kind, i->t->value);
			j = i;
			while (j != NULL && j->t->kind == TO_WORD)
				j = j->next;
			make_token_group(i, j);
			if ((tokens_len = ft_tlistlen(*tokens)) - 1 <= (size_t)ft_tlisti(i))
			{
				break ;
			}
			ft_put("after\n");
		}
		i = i->next;
	}
	make_cmd(*tokens);
	ft_put("OUT OF MAKE_TOKEN_GROUPS\n");
}
