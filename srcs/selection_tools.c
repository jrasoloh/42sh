/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:35:29 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/25 17:00:32 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

int					enter_selection_mode(void)
{
	g_edit->sel_origin = g_edit->cursor;
	return (1);
}

void				undo_selection(void)
{
	t_line			*line;

	if ((line = g_edit->first) == NULL)
		return ;
	while (line != NULL)
	{
		line->selected = 0;
		line = line->next;
	}
}

void				print_line_cursorless(void)
{
	g_edit->cursor->cursor = 0;
	print_line();
}

void				free_selection(void)
{
	t_line			*damned;
	t_line			*line;

	if ((line = g_edit->selected) == NULL)
		return ;
	damned = line;
	while (line != NULL)
	{
		damned = line;
		line = line->next;
		free(damned);
	}
	g_edit->selected = NULL;
}

int 				exit_selection_mode(void)
{
	undo_selection();
	g_edit->mode = 0;
	g_edit->sel_origin = NULL;
	g_edit->sel_direction = 0;
	return (0);
}
