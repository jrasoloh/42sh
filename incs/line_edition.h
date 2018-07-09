/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:34:27 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/06/25 16:12:21 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITION_H
# define LINE_EDITION_H

# define NO_COLOR			"\033[0m"
# define SELECTION_COLOR	"\033[30;42m"
# define CURSOR_COLOR		"\033[5;30;47m"

# define TO_K_UP			"\e[A"
# define TO_K_DOWN			"\e[B"
# define TO_K_RIGHT			"\e[C"
# define TO_K_LEFT			"\e[D"

# define TO_K_END			"\e[F"
# define TO_K_HOME			"\e[H"

# define TO_K_DEL_FWD		"\e[3~"
# define TO_READ_SIZE		7
# define TO_K_ESC			'\e'
# define TO_K_DEL			127
# define TO_K_BAC			126
# define TO_K_RET			10
# define TO_K_SPA			' '

# define TO_K_SHIFT_UP		"\e[1;2A"
# define TO_K_SHIFT_DOWN	"\e[1;2B"
# define TO_K_SHIFT_LEFT	"\e[1;2D"
# define TO_K_SHIFT_RIGHT	"\e[1;2C"

# define TO_K_OPT_LEFT		"\e\e[D"
# define TO_K_OPT_RIGHT		"\e\e[C"

# define TO_K_CTRL_UP		"\e[1;5A"
# define TO_K_CTRL_DOWN		"\e[1;5B"

# define LEFT				0
# define RIGHT				1

# define STANDARD			0
# define QUOTE				1
# define DQUOTE				2

typedef struct			s_caps
{
	char				*up;
	char				*cr;
	char				*cd;
	char				*clr;
	char				*gto;
	char				*sta;
	char				*ste;
	char				*hic;
	char				*shc;
	char				*sav;
	char				*res;
	char				*ula;
	char				*ule;
	char				*lft;
	char				*rgt;
	char				*ins;
	char				*qin;
	char				*cin;
}						t_caps;

typedef struct			s_history
{
	char				*cmd;
	struct s_history	*previous;
	struct s_history	*next;
}						t_history;

typedef struct			s_line
{
	char				data;
	char				cursor;
	char				selected;
	char				line_type;
	char				line_level;
	struct s_line		*next_line;
	struct s_line		*previous;
	struct s_line		*next;
}						t_line;

typedef struct			s_edit
{
	t_line				*cursor;
	t_line				*sel_origin;
	t_line				*first;
	t_line				*head_list;
	t_line				*selected;
	char				sel_direction;
	char				mode;
	t_history			*history;
}						t_edit;

t_edit					*g_edit;

/*
** cursor_tools.c
*/
void					check_cursor(void);
void					move_cursor_to_tail(void);
void					reset_cursor(void);
void					update_cursor_selection(void);

/*
** edit_line.c
*/
int						event(char *c, t_caps *caps);
int 					edit_loop();

/*
** edit_tools.c
*/
int						ft_is_printable(int c);
void					init_edit(void);

/*
** history.c
*/
void					add_to_history(char *line);
void					clear_history(void);
t_history				*create_history(char *line);
int						get_whole_length(void);
void					reset_history(void);

/*
** line_basics.c
*/
void					add_to_line(char c);
t_line					*create_line(char c);
void					del_last_char(void);
t_line					*new_line(void);
void					print_line(void);

/*
** line_delete.c
*/
void					del_next_char(void);

/*
** line_tools.c
*/
void					del_line(void);
int						get_length(void);
void					print_cursor(char c);
void					print_selection(char c);
char					*convert_line(void);

/*
** line_update.c
*/
int						get_line_number(void);
void					update_first(void);
void					update_onscreen(int line_number);
void					update_selected(void);

/*
** move.c
*/
void					move_down(void);
void					move_left(void);
void					move_right(void);
void					move_up(void);

/*
** move_by_word.c
*/
void					go_to_head(void);
void					go_to_next_word(void);
void					go_to_previous_word(void);
void					go_to_tail(void);

/*
** quotes.c
*/
void					add_return_to_line(int quote);
int						eval_line(void);
void					print_quote_prompt(int c);

/*
** selection.c
*/
void					delete_selection(void);
t_line					*go_to_first_selected(void);
t_line					*go_to_last_selected(void);
t_line					*make_twin(t_line *line);
void					paste_selection(void);

/*
** selection_tools.c
*/
int						enter_selection_mode(void);
int						exit_selection_mode(void);
void					free_selection(void);
void					print_line_cursorless(void);
void					undo_selection(void);

#endif
