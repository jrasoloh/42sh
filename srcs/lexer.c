/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:16:55 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/18 15:02:37 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

static int		end_of_value(char *s, int start)
{
	char	first;
	int		i;

	first = s[start];
	i = start + 1;
	while (s[i])
	{
		if (is_cpartofw(first) && !is_cpartofw(s[i]))
			return (i - 1);
		else if (first == '"' && s[i] == '"')
			return (i);
		else if (first == '<')
			return ((s[i] == '<') ? i : i - 1);
		else if (first == '>')
			return ((s[i] == '>') ? i : i - 1);
		else if (first == '|' || first == ';')
			return (i - 1);
		else if ((first != '|' && first != '>' && first != '<'
					&& first != '"' && !is_cpartofw(first)) && s[i] == ' ')
			return (i - 1);
		i++;
	}
	return (i - 1);
}

static int		kind_of_value(char *s)
{
	size_t	s_len;
	int		i;

	s_len = ft_strlen(s);
	i = 0;
	if (is_cpartofw(s[0]))
	{
		while (s[i] && is_cpartofw(s[i]))
			i++;
		if ((int)ft_strlen(s) == i)
			return (TO_WORD);
	}
	else if (s[0] == '"' && s[s_len - 1] == '"')
		return (TO_WORD);
	else if ((s[0] == '<' || ft_strcmp(s, "<<") == 0)
			|| (s[0] == '>' || ft_strcmp(s, ">>") == 0))
		return (TO_REDIR);
	else if (s[0] == '|')
		return (TO_PIPE);
	return (TO_UK);
}

static t_token	*make_token(char *s, int start, int end)
{
	t_token	*t;

	if ((t = (t_token*)malloc(sizeof(t_token))) == NULL)
		return (NULL);
	t->value = ft_strsub(s, start, (end - start) + 1);
	t->kind = kind_of_value(t->value);
	t->args = NULL;
	return (t);
}

t_tlist			*lexe(char *input)
{
	t_tlist	*tokens;
	int		i;
	int		val_start;
	int		val_end;

	tokens = NULL;
	i = -1;
	val_start = -1;
	val_end = 0;
	while (input[++i])
	{
		val_start = i;
		val_end = end_of_value(input, i);
		ft_tlistappn(&tokens, make_token(input, val_start, val_end));
		/* add_token(&tokens, make_token(input, val_start, val_end)); */
		i = next_nonblank(input, val_end) - 1;
	}
	print_tokens(tokens);
	make_token_groups(&tokens);
	print_tokens(tokens);
	return (tokens);
}
