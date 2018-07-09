/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:10:57 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/25 16:11:01 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

t_line					*create_line(char c)
{
	t_line				*line;

	if ((line = (t_line *)ft_memalloc(sizeof(t_line))) == NULL)
		return (NULL);
	line->data = c;
	line->previous = NULL;
	line->next = NULL;
	line->cursor = 0;
	line->selected = 0;
	line->line_type = STANDARD;
	line->line_level = 0;
	return (line);
}

t_line					*new_line(void)
{
	t_line				*line;

	if ((line = create_line(' ')) == NULL)
			return (NULL);
	line->cursor = 1;
	line->selected = 0;
	return (line);
}

void					add_to_line(char c)
{
	t_line				*new;
	t_line				*cursor;

	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
	if ((new = create_line(c)) == NULL)
		return ;
	new->line_level = g_edit->cursor->line_level;
	new->line_type = g_edit->cursor->line_type;
	cursor = g_edit->cursor;
	new->next = cursor;
	if (cursor->previous != NULL)
	{
		cursor->previous->next = new;
		new->previous = cursor->previous;
	}
	cursor->previous = new;
	update_first();
}

void					del_last_char(void)
{
	t_line				*damned;

	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
	if (g_edit->cursor->previous == NULL
		|| g_edit->cursor->previous->line_level != g_edit->cursor->line_level)
		return ;
	damned = g_edit->cursor->previous;
	if (damned->previous != NULL)
	{
		damned->previous->next = g_edit->cursor;
		g_edit->cursor->previous = damned->previous;
	}
	else
		g_edit->cursor->previous = NULL;
	free(damned);
	update_first();
}

void					print_char(t_line *line)
{
	if (g_edit->mode == 0)
	{
		if (line->cursor == 0)
			ft_putchar(line->data);
		else
			print_cursor(line->data);
	}
	else
	{
		if (line == g_edit->sel_origin)
			print_selection(line->data);
		else if (line->selected == 0)
			ft_putchar(line->data);
		else
			print_cursor(line->data);
	}
}

void					print_correct_prompt(t_line *line)
{
	if (line->line_level == 0)
	{
		if (save_pwd(NULL) != NULL)
		{
			ft_putstr(save_pwd(NULL));
			ft_putstr("> ");
		}
		else
			ft_putstr("$> ");
	}
	else
		print_quote_prompt(line->line_type);
}

void					print_line(void)
{
	t_line				*line;

	line = g_edit->first;
	print_correct_prompt(line);
	while (line != NULL)
	{
		if (line->data == '\n' && line->line_level != g_edit->first->line_level)
		{
			ft_putchar('\n');
			print_quote_prompt(line->line_type);
		}
		else
			print_char(line);
		line = line->next;
	}
	update_first();
}
