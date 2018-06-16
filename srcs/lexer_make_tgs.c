/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_make_tgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:28:46 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/21 15:24:19 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

static void	remove_arg_words(t_token ***tokens, int start, int args_len)
{
	t_token	**new;
	size_t	new_len;
	int		new_i;
	int		i;

	new_len = ntarr_len(*tokens) - args_len;
	ft_put("oldlen: %d\tnewlen: %d\targs_len: %d\n", ntarr_len(*tokens), new_len, args_len);
	new = (t_token**)malloc(sizeof(t_token*) * (new_len + 1));
	new[new_len] = NULL;
	new_i = 0;
	i = 0;
	ft_put("start: %d, full: %d\n", start, start + args_len);
	/* while ((*tokens)[i] && i < (int)new_len) */
	while ((*tokens)[i])
	{
		ft_put("___value: '%s'\tkind: %d\ti: %d\tj: %d\n",
				(*tokens)[i]->value, (*tokens)[i]->kind, new_i, i);
		if (!(i > start && i <= start + args_len))
		{
			ft_put("---value: '%s'\tkind: %d\ti: %d\tj: %d\n",
					(*tokens)[i]->value, (*tokens)[i]->kind, new_i, i);
			new[new_i] = (*tokens)[i];
			new_i++;
		}
		i++;
	}
	ft_put("END OF REMOVE_ARG_WORDS\n");
	free(*tokens);
	*tokens = new;
}

static void	make_token_group(t_token ***tokens, int start, int end)
{
	int	args_len;
	int	i;
	int	j;

	args_len = end - start;
	ft_put("end:%d - start:%d = %d\n", end, start, end - start);
	ft_put("args_len: %d\n", args_len);
	(*tokens)[start]->kind = TO_GRP;
	(*tokens)[start]->args = (char**)malloc(sizeof(char*) * (args_len + 1));
	(*tokens)[start]->args[args_len] = NULL;
	i = -1;
	j = start + 1;
	/* ft_put("args len %d\n", ft_ntsarr_len((*tokens)[start]->args)); */
	/* ft_put("tokens len %d\n", ntarr_len(*tokens)); */
	while (++i < args_len)
	{
		ft_put("group iter %d, %d\n", i, j);
		(*tokens)[start]->args[i] = (*tokens)[j]->value;
		j++;
	}
	ft_put("after\n");
	remove_arg_words(tokens, start, args_len);
}

static void	make_cmd(t_token **tokens)
{
	int	i;

	i = -1;
	while (tokens[++i])
	{
		if (i > 0 && tokens[i]->kind == TO_WORD)
		{
			if (tokens[i - 1]->kind == TO_REDIR)
				tokens[i]->kind = TO_FILE;
			else
				tokens[i]->kind = TO_CMD;
		}
		else if (i == 0 && tokens[i]->kind == TO_WORD)
				tokens[i]->kind = TO_CMD;
	}
}

void		make_token_groups(t_token ***tokens)
{
	size_t	tokens_len;
	int		i;
	int		j;

	tokens_len = ntarr_len(*tokens);
	i = -1;
	while ((*tokens)[++i])
	{
		if (i > 0 && (*tokens)[i - 1]->kind == TO_WORD && (*tokens)[i]->kind == TO_WORD)
		{
			ft_put("current token: %d, '%s'\n", (*tokens)[i]->kind, (*tokens)[i]->value);
			j = i;
			while ((*tokens)[j] && (*tokens)[j]->kind == TO_WORD)
			{
				ft_put("make_token iter %d\n", j);
				j++;
			}
			ft_put("========================================= %d, %d\n", i, j);
			make_token_group(tokens, i - 1, j - 1);
			if ((tokens_len = ntarr_len(*tokens)) - 1 <= (size_t)i)
			{
				ft_put("*************************** => tok_len: %d, i: %d\n", tokens_len, i);
				break ;
			}
			ft_put("after\n");
		}
	}
	make_cmd(*tokens);
	ft_put("OUT OF MAKE_TOKEN_GROUPS\n");
}
