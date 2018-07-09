/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_by_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 13:09:53 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/24 21:23:30 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

void			go_to_head(void)
{
	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
	g_edit->cursor->cursor = 0;
	g_edit->first->cursor = 1;
	reset_cursor();
}

void			go_to_tail(void)
{
	t_line		*tmp;

	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
	if (g_edit->cursor->next == NULL)
		return ;
	tmp = g_edit->cursor;
	while (tmp->next != NULL)
		tmp = tmp->next;
	g_edit->cursor->cursor = 0;
	tmp->cursor = 1;
	reset_cursor();
}

void			go_to_next_word(void)
{
	t_line		*tmp;
	t_line		*tmp1;

	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
	if (g_edit->cursor->next == NULL)
		return ;
	tmp = g_edit->cursor;
	tmp1 = tmp;
	while (tmp->next != NULL && !ft_isblank(tmp->next->data))
		tmp = tmp->next;
	while (tmp->next != NULL && ft_isblank(tmp->next->data))
		tmp = tmp->next;
	g_edit->cursor->cursor = 0;
	if (tmp->next != NULL)
		tmp->next->cursor = 1;
	else
		tmp1->cursor = 1;
	reset_cursor();
}

void			go_to_previous_word(void)
{
	t_line		*tmp;
	t_line		*tmp1;

	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
	if (g_edit->cursor->previous == NULL)
		return ;
	tmp = g_edit->cursor;
	while (tmp->previous != NULL && !ft_isblank(tmp->previous->data))
		tmp = tmp->previous;
	tmp1 = tmp;
	while (tmp->previous != NULL && ft_isblank(tmp->previous->data))
		tmp = tmp->previous;
	while (tmp->previous != NULL && !ft_isblank(tmp->previous->data))
		tmp = tmp->previous;
	g_edit->cursor->cursor = 0;
	if (!ft_isblank(tmp->data))
		tmp->cursor = 1;
	else
		tmp1->cursor = 1;
	reset_cursor();
}
void					init_edit(void);
