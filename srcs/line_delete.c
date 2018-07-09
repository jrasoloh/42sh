/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:11:42 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/25 14:58:33 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

void					del_next_char(void)
{
	t_line				*damned;

	if (g_edit->cursor == NULL || g_edit->cursor->cursor != 1)
		reset_cursor();
	if (g_edit->cursor == NULL)
		return ;
	damned = g_edit->cursor;
	if (damned->next != NULL)
	{
		damned->next->cursor = 1;
		g_edit->cursor = damned->next;
		damned->next->previous = damned->previous;
		damned->previous->next = damned->next;
		free(damned);
		update_first();
		reset_cursor();
	}
}
