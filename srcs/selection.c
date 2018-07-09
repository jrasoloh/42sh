/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:03:26 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/25 16:14:02 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

t_line				*go_to_first_selected(void)
{
	t_line			*line;

	line = g_edit->first;
	if (line->selected == 1)
		return (line);
	else
	{
		while (line != NULL && line->next != NULL && line->selected == 0)
			line = line->next;
		return (line);
	}
	return (NULL);
}

t_line				*go_to_last_selected(void)
{
	t_line			*line;

	line = go_to_first_selected();
	if (line->next == NULL)
		return (line);
	while (line != NULL && line->next != NULL && line->next->selected == 1)
		line = line->next;
	return (line);
}

void				delete_selection(void)
{
	t_line			*tmp;
	t_line			*tail;

	check_cursor();
	if ((tmp = go_to_first_selected()) == NULL)
		return ;
	tail = go_to_last_selected();
	update_cursor_selection();
	if (g_edit->selected != NULL)
		free_selection();
	g_edit->selected = tmp;
	if (tmp->previous != NULL && tail->next != NULL)
	{
		tmp->previous->next = tail->next;
		tail->next->previous = tmp->previous;
	}
	else if (tmp->previous != NULL)
		tmp->previous->next = NULL;
	else if (tail->next != NULL)
		tail->next->previous = NULL;
	tmp->previous = NULL;
	tail->next = NULL;
	update_first();
	exit_selection_mode();
}

t_line				*copy_line(t_line *line)
{
	t_line			*copy;

	if (line == NULL || ((copy = create_line(line->data)) == NULL))
		return (NULL);
	copy->line_type = g_edit->cursor->line_type;
	copy->line_level = g_edit->cursor->line_level;
	return (copy);
}

t_line				*make_twin(t_line *line)
{
	t_line			*head;
	t_line			*copy;
	t_line			*before;

	if (line == NULL)
		return (NULL);
	if ((head = copy_line(line)) == NULL)
		return (NULL);
	before = head;
	copy = NULL;
	line = line->next;
	while (line != NULL)
	{
		if ((copy = copy_line(line)) == NULL)
			return (NULL);
		before->next = copy;
		copy->previous = before;
		before = copy;
		line = line->next;
	}
	return (head);
}

/* void				print_vitefait(t_line *line) */
/* { */
/* 	if (line == NULL) */
/* 		ft_putendl("LIGNE VIDE"); */
/* 	while (line != NULL) */
/* 	{ */
/* 		ft_putchar(line->data); */
/* 		line = line->next; */
/* 	} */
/* 	ft_putchar('\n'); */
/* } */

void				paste_selection(void)
{
	t_line			*copy;
	t_line			*before;

	check_cursor();
	if (g_edit->selected == NULL)
		return ;
	if (g_edit->cursor->previous != NULL)
		before = g_edit->cursor->previous;
	if ((copy = make_twin(g_edit->selected)) == NULL)
		return ;
	if (before != NULL)
	{
		copy->previous = before;
		before->next = copy;
	}
	while (copy->next != NULL)
		copy = copy->next;
	copy->next = g_edit->cursor;
	g_edit->cursor->previous = copy;
	update_first();
}
