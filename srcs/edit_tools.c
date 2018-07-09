/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:48:28 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/25 16:17:24 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

int					ft_is_printable(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void				init_edit(void)
{
	t_edit			*edit;

	if ((edit = (t_edit *)malloc(sizeof(t_edit))) == NULL)
		return ;
	edit->first = new_line();
	edit->cursor = edit->first;
	edit->sel_origin = NULL;
	edit->selected = NULL;
	edit->mode = 0;
	edit->history = NULL;
	edit->sel_direction = LEFT;
	g_edit = edit;
}
