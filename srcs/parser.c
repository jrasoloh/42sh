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
	print_token(((t_tlist*)data)->t);
}

t_tlist			*find_next_op(t_tlist *tokens)
{
	ft_put("in find_next_op\n");
	t_tlist	*iter;
	int		kind;

	iter = tokens;
	while (iter != NULL)
	{
		/* ft_put("begin: %d\n", begin); */
		kind = iter->t->kind;
		if (kind == TO_OP
				|| kind == TO_REDIR
				|| kind == TO_PIPE)
		{
			/* ft_put("returning %p\n", iter); */
			ft_put("out find_next_op\n");
			return (iter);
		}
		iter = iter->prev;
	}
	ft_put("out(null) find_next_op\n");
	return (NULL);
}

static t_bst	*make_ast(t_tlist *tokens)
{
	t_bst	*cur_node;
	t_tlist	*op;

	op = find_next_op(tokens);
	if (op == NULL)
	{
		ft_put("[PARSER] no operators left\n");
		return (ft_bstnew(tokens));
	}
	cur_node = ft_bstnew(op);
	cur_node->right = ft_bstnew(op->next);
	cur_node->left = make_ast(op->prev);
	return (cur_node);
}

t_bst			*parse(t_tlist *tokens)
{
	t_bst	*ast;
	size_t	tokens_len;

	ast = NULL;
	tokens_len = ft_tlistlen(tokens);
	ft_put("-----------------------\nstarting parser\n");
	ast = make_ast(ft_tlistlast(tokens));
	ft_put("parser has ended\n-----------------------\n");
	if (ast == NULL)
		ft_put("ast is null\n");
	ft_put("/ PRINTING AST \\\n");
	ft_bstiter_inorder(ast, &print_ast);
	ft_put("\\ PRINTING AST /\n");
	return (ast);
}
