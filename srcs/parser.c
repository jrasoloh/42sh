/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:36:33 by echojnow          #+#    #+#             */
/*   Updated: 2018/05/03 19:18:41 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void	print_ast(void *data)
{
	print_token((t_token*)data);
}

int				find_next_op(t_token **tokens, int begin)
{
	int	kind;

	while (begin > 0)
	{
		ft_put("begin: %d\n", begin);
		kind = tokens[begin]->kind;
		if (kind == TO_OP
				|| kind == TO_REDIR
				|| kind == TO_PIPE)
		{
			ft_put("returning %d\n", begin);
			return (begin);
		}
		begin--;
	}
	return (-1);
}

static t_bst	*make_ast(t_token **tokens, int start)
{
	t_bst	*cur_node;
	int		op_i;

	op_i = find_next_op(tokens, start);
	if (op_i == -1)
	{
		ft_put("[PARSER] no operators left\n");
		return (ft_bstnew(tokens[0]));
	}
	cur_node = ft_bstnew(tokens[op_i]);
	cur_node->right = ft_bstnew(tokens[op_i + 1]);
	cur_node->left = make_ast(tokens, op_i - 1);
	return (cur_node);
}

t_bst			*parse(t_token **tokens)
{
	t_bst	*ast;
	size_t	tokens_len;

	ast = NULL;
	tokens_len = ntarr_len(tokens);
	ft_put("-----------------------\nstarting parser\n");
	ast = make_ast(tokens, ntarr_len(tokens) - 1);
	ft_put("parser has ended\n-----------------------\n");
	if (ast == NULL)
		ft_put("ast is null\n");
	ft_put("PRINTING AST\n");
	ft_bstiter_inorder(ast, &print_ast);
	return (ast);
}
