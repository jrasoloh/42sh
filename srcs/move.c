/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:44:37 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/22 13:57:42 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

void			move_right(void)
{
	t_line		*crs;

	check_cursor();
	crs = g_edit->cursor;
	if (crs->next != NULL && crs->next->line_level == crs->line_level)
	{
		if (g_edit->mode == 1 && crs->next->next != NULL)
		{
			if (crs == g_edit->sel_origin)
				g_edit->sel_direction = RIGHT;
			crs->selected = (g_edit->sel_direction == RIGHT) ? 1 : 0;
			crs->next->selected = (g_edit->sel_direction == RIGHT) ? 1 : 0;
		}
		crs->cursor = 0;
		crs->next->cursor = 1;
		reset_cursor();
	}
}

void			move_left(void)
{
	t_line		*crs;

	check_cursor();
	crs = g_edit->cursor;
	if (crs->previous != NULL && crs->previous->data != '\n'
		&& crs->previous->line_level == crs->line_level)
	{
		if (g_edit->mode == 1)
		{
			if (crs == g_edit->sel_origin)
			{
				g_edit->sel_direction = LEFT;
				crs->selected =
					(crs->next != NULL && crs->next->selected == 1) ? 1 : 0;
			}
			else
				crs->selected = (g_edit->sel_direction == LEFT) ? 1 : 0;
			crs->previous->selected = (g_edit->sel_direction == LEFT) ? 1 : 0;
		}
		crs->cursor = 0;
		crs->previous->cursor = 1;
		reset_cursor();
	}
}

void			move_up(void)
{
	int			height;
	int			width;
	int			i;
	t_line		*crs;

	check_cursor();
	crs = g_edit->cursor;
	get_winsize(&width, &height);
	i = width;
	while (i > 0 && crs->previous != NULL && crs->previous->data != '\n'
		&& crs->previous->line_level == crs->line_level)
	{
		if (g_edit->mode == 1)
		{
			if (crs == g_edit->sel_origin)
			{
				g_edit->sel_direction = LEFT;
				crs->selected =
					(crs->next != NULL && crs->next->selected == 1) ? 1 : 0;
			}
			else
				crs->selected = (g_edit->sel_direction == LEFT) ? 1 : 0;
			crs->previous->selected = (g_edit->sel_direction == LEFT) ? 1 : 0;
		}
		crs = crs->previous;
		i--;
	}
	g_edit->cursor->cursor = 0;
	crs->cursor = 1;
	reset_cursor();
}

void			move_down(void)
{
	int			height;
	int			width;
	int			i;
	t_line		*crs;

	check_cursor();
	crs = g_edit->cursor;
	get_winsize(&width, &height);
	i = 0;
	while (i < width && crs->next != NULL
			&& crs->next->line_level == crs->line_level)
	{
		if (g_edit->mode == 1 && crs->next->next != NULL)
		{
			if (crs == g_edit->sel_origin)
				g_edit->sel_direction = RIGHT;
			crs->selected = (g_edit->sel_direction == RIGHT) ? 1 : 0;
			crs->next->selected = (g_edit->sel_direction == RIGHT) ? 1 : 0;
		}
		crs = crs->next;
		i++;
	}
	g_edit->cursor->cursor = 0;
	crs->cursor = 1;
	reset_cursor();
}
