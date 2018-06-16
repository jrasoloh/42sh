/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_memo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:03:37 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/16 12:03:24 by jrasoloh         ###   ########.fr       */
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
	return (line);
}

t_line					*new_line(void)
{
	t_line				*line;

	if ((line = create_line(' ')) == NULL)
			return (NULL);
	line->cursor = 1;
	return (line);
}

void					init_edit(void)
{
	t_edit				*edit;

	if ((edit = (t_edit *)malloc(sizeof(t_edit))) == NULL)
		return ;
	edit->first = new_line();
	edit->cursor = edit->first;
	g_edit = edit;
}

void					reset_cursor(void)
{
	t_line				*line;

	line = g_edit->first;
	while (line != NULL && line->next != NULL && line->cursor == 0)
		line = line->next;
	g_edit->cursor = line;
}

void					update_first(void)
{
	t_line				*line;

	line = g_edit->cursor;
	while (line->previous != NULL)
		line = line->previous;
	g_edit->first = line;
}

void					add_to_line(char c)
{
	t_line				*new;
	t_line				*cursor;

	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
	if ((new = create_line(c)) == NULL)
		return ;
	cursor = g_edit->cursor;
	new->previous = cursor->previous;
	new->next = cursor;
	if (cursor->previous != NULL)
		cursor->previous->next = new;
	cursor->previous = new;
	update_first();
}

void					del_last_char(void)
{
	t_line				*damned;

	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
	if (g_edit->cursor->previous == NULL)
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

void					del_line(void)
{
	t_line				*current;
	t_line				*next;

	current = g_edit->first;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	g_edit->first = new_line();
	g_edit->cursor = g_edit->first;
}

int						get_length(void)
{
	int					len;
	t_line				*line;

	line = g_edit->first;
	len = 1;
	while (line->next != NULL)
	{
		len++;
		line = line->next;
	}
	return (len);
}

void					print_cursor(char c)
{
	ft_putstr(CURSOR_COLOR);
	ft_putchar(c);
	ft_putstr(NO_COLOR);
}

void					print_line(void)
{
	t_line				*line;

	line = g_edit->first;
	while (line != NULL)
	{
		if (line->cursor == 0)
			ft_putchar(line->data);
		else
			print_cursor('Z');
		line = line->next;
	}
}

char					*submit_line(void)
{
	char				*res;
	int					i;
	t_line				*line;

	line = g_edit->first;
	if ((res = (char *)malloc(sizeof(char) * (get_length()))) == NULL)
		return (NULL);
	i = 0;
	while (i <= get_length())
	{
		res[i] = line->data;
		line = line->next;
		i++;
	}
	res[i] = '\0';
	return (res);
}
