/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:44:37 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/22 13:57:42 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

t_history				*create_history(char *line)
{
	t_history			*hist;

	if (line == NULL)
		return (NULL);
	if ((hist = (t_history *)ft_memalloc(sizeof(t_history))) == NULL)
		return (NULL);
	hist->cmd = ft_strdup(line);
	hist->previous = NULL;
	hist->next = NULL;
	return (hist);
}

void					reset_history(void)
{
	t_history			*hist;

	if (g_edit->history == NULL)
		return ;
	if (g_edit->history->next != NULL)
	{
		hist = g_edit->history;
		while (hist->next != NULL)
			hist = hist->next;
		g_edit->history = hist;
	}
}

void					add_to_history(char *line)
{
	t_history			*hist;

	reset_history();
	if ((hist = create_history(line)) == NULL)
		return ;
	if (g_edit->history == NULL)
		g_edit->history = hist;
	else
	{
		g_edit->history->next = hist;
		hist->previous = g_edit->history;
		g_edit->history = hist;
	}
}

void					clear_history(void)
{
	t_history			*damned;
	t_history			*before;

	reset_history();
	if (g_edit->history == NULL)
		return ;
	damned = g_edit->history;
	while (damned->previous != NULL)
	{
		before = damned->previous;
		free(damned);
		damned = before;
	}
	free(damned);
	g_edit->history = NULL;
}

int						get_whole_length(void)
{
	int					len;
	t_line				*line;

	line = g_edit->head_list;
	len = 1;
	while (line->next != NULL && line->next->next != NULL)
	{
		len++;
		line = line->next;
	}
	return (len);
}
