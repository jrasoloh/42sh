/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:44:37 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/22 13:57:42 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

void				check_cursor(void)
{
	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
}

void				reset_cursor(void)
{
	t_line			*line;

	line = g_edit->first;
	while (line != NULL && line->next != NULL && line->cursor == 0)
		line = line->next;
	g_edit->cursor = line;
}

void				update_cursor_selection(void)
{
	t_line			*crs;

	check_cursor();
	crs = g_edit->cursor;
	if (crs->selected == 1)
	{
		if (crs->previous != NULL && crs->previous->selected == 0)
		{
			crs->cursor = 0;
			crs->previous->cursor = 1;
		}
		else if (crs->next != NULL && crs->next->selected == 0)
		{
			crs->cursor = 0;
			crs->next->cursor = 1;
		}
		else
		{
			while (crs->next != NULL && crs->next->selected == 1)
				crs = crs->next;
			g_edit->cursor->cursor = 0;
			crs->cursor = 1;
		}
		reset_cursor();
	}
}

void					move_cursor_to_tail(void)
{
	t_line				*cursor;

	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
	cursor = g_edit->cursor;
	if (cursor->next != NULL && cursor->next->next == NULL)
		return ;
	while (cursor->next != NULL)
		cursor = cursor->next;
	g_edit->cursor->cursor = 0;
	cursor->cursor = 1;
	reset_cursor();
}
