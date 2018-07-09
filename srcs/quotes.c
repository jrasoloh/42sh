/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:03:26 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/25 16:14:02 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

void					print_quote_prompt(int c)
{
	if (c == QUOTE)
		ft_putstr("quote> ");
	else if (c == DQUOTE)
		ft_putstr("dquote> ");
	else
		ft_putstr("> ");
}

void					add_return_to_line(int quote)
{
	t_line				*new;
	t_line				*cursor;

	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
	move_cursor_to_tail();
	if ((new = create_line('\n')) == NULL)
		return ;
	new->line_type = quote;
	new->line_level = g_edit->cursor->line_level + 1;
	cursor = g_edit->cursor;
	cursor->line_level++;
	cursor->line_type = new->line_type;
	new->next = cursor;
	if (cursor->previous != NULL)
	{
		cursor->previous->next = new;
		new->previous = cursor->previous;
	}
	cursor->previous = new;
}

int						eval_line(void)
{
	t_line				*line;
	int					val;

	val = 0;
	if ((line = g_edit->head_list) == NULL)
		return (0);
	while (line->next != NULL)
	{
		if (line->data == '\'' && val == 0)
			val = 1;
		else if (line->data == '"' && val == 0)
			val = 2;
		else if ((line->data == '\'' && val == 1) ||
				(line->data == '"' && val == 2))
			val = 0;
		line = line->next;
	}
	return (val);
}
