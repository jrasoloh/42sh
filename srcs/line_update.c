/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:52:27 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/25 16:56:53 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

int				get_line_number(void)
{
	int			nb;
	t_line		*line;
	int			prompt;
	int			height;
	int			width;

	get_winsize(&width, &height);
	check_cursor();
	line = g_edit->first;
	nb = 0;
	if (line->line_type == STANDARD)
		prompt = (save_pwd(NULL) != NULL) ? (ft_strlen(save_pwd(NULL)) + 1) : 4;
	else
		prompt = (line->line_type == QUOTE) ? 5 : 6;
	nb = (get_length() + prompt) / width;
	return (nb);
}

void			update_onscreen(int line_number)
{
	t_caps	*caps;

	caps = save_caps(NULL);
	while (line_number > 0)
	{
		ft_putstr(caps->up);
		line_number--;
	}
	ft_putstr(caps->cr);
	ft_putstr(caps->cd);
	print_line();
}

void			update_first(void)
{
	t_line		*line;

	line = g_edit->cursor;
	while (line->previous != NULL && line->previous->data != '\n'
			&& line->previous->line_level == g_edit->cursor->line_level)
		line = line->previous;
	g_edit->first = line;
	while (line->previous != NULL)
		line = line->previous;
	g_edit->head_list = line;

}

void			update_selected(void)
{
	t_line		*line;

	line = g_edit->first;
	while (line != NULL && line->selected == 0)
		line = line->next;
	g_edit->selected = line;
}
