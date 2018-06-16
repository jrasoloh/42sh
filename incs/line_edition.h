/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:34:27 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/16 12:14:10 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITION_H
# define LINE_EDITION_H

# include "twentyonesh.h"

# define NO_COLOR		"\x1b[0m"
# define CURSOR_COLOR	"\033[0;32m"

typedef struct	s_caps
{
	char	*clr;
	char	*gto;
	char	*sta;
	char	*ste;
	char	*hic;
	char	*shc;
	char	*sav;
	char	*res;
	char	*ula;
	char	*ule;
	char	*lft;
	char	*rgt;
	char	*ins;
	char	*qin;
	char	*cin;
}				t_caps;

typedef struct			s_line
{
	char				data;
	char				cursor;
	struct s_line		*previous;
	struct s_line		*next;
}						t_line;

typedef struct			s_edit
{
	t_line				*cursor;
	t_line				*first;
}						t_edit;

t_edit					*g_edit;

/*
** line_memo.c
*/
void					add_to_line(char c);
t_line					*create_line(char c);
void					del_last_char(void);
void					del_line(void);
int						get_length(void);
void					init_edit(void);
t_line					*new_line(void);
void					print_line(void);
void					reset_cursor(void);
char					*submit_line(void);

/*
** edit_line.c
*/
int						event(char *c, t_caps *caps);
int						edit_loop();

#endif
