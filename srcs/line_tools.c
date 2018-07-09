/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:02:58 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/24 20:06:41 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"

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
	while (line->next != NULL && line->line_level == g_edit->first->line_level)
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

void					print_selection(char c)
{
		ft_putstr(SELECTION_COLOR);
		ft_putchar(c);
		ft_putstr(NO_COLOR);
}

char					*convert_line(void)
{
	char				*res;
	int					i;
	t_line				*line;

	line = g_edit->head_list;
	if ((res = (char *)malloc(sizeof(char) * (get_whole_length()))) == NULL)
		return (NULL);
	i = 0;
	while (i < get_whole_length())
	{
		res[i] = line->data;
		line = line->next;
		i++;
	}
	res[i] = '\0';
	return (res);
}
