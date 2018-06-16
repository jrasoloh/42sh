/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:23:21 by echojnow          #+#    #+#             */
/*   Updated: 2018/05/22 15:09:04 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

int	init_caps(t_caps *caps)
{
	caps->clr = tgetstr("cl", NULL);
	caps->gto = tgetstr("cm", NULL);
	caps->sta = tgetstr("so", NULL);
	caps->ste = tgetstr("se", NULL);
	caps->hic = tgetstr("vi", NULL);
	caps->shc = tgetstr("ve", NULL);
	caps->sav = tgetstr("ti", NULL);
	caps->res = tgetstr("te", NULL);
	caps->ula = tgetstr("us", NULL);
	caps->ule = tgetstr("ue", NULL);
	caps->lft = tgetstr("le", NULL);
	caps->rgt = tgetstr("nd", NULL);
	return (0);
}

struct termios	*save_orig_termios(struct termios *orig_termios)
{
	static struct termios	*saved_orig_termios = NULL;

	if (orig_termios != NULL)
		saved_orig_termios = orig_termios;
	return (saved_orig_termios);
}
t_caps			*save_caps(t_caps *caps)

{
	static t_caps	*saved_caps = NULL;

	if (caps != NULL)
		saved_caps = caps;
	return (saved_caps);
}

int				save_fd(int fd)
{
	static int	saved_fd;

	if (saved_fd != -1)
		saved_fd = fd;
	return (saved_fd);
}

void	exit_term()
{
	int	fd;
	t_caps *caps;

	fd = save_fd(-1);
	restore_term();
	caps = save_caps(NULL);
	close(fd);
	exit(0);
}

void	configure_term(void)
{
	struct termios	*orig_termios;
	t_caps			*caps;
	int				fd;
	struct termios	raw;

	orig_termios = save_orig_termios(NULL);
	caps = save_caps(NULL);
	fd = save_fd(-1);
	raw = *orig_termios;
	raw.c_lflag &= ~(ECHO | ICANON);
	/* raw.c_oflag &= ~(OPOST); */
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
	ft_putstr_fd(caps->hic, fd);
	ft_putstr_fd(caps->sav, fd);
	tgetent(0, getenv("TERM"));
}

void	restore_term(void)
{
	struct termios	*orig_termios;
	t_caps			*caps;
	int				fd;

	orig_termios = save_orig_termios(NULL);
	caps = save_caps(NULL);
	fd = save_fd(-1);
	ft_putstr_fd(caps->res, fd);
	ft_putstr_fd(caps->shc, fd);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios);
}

int		get_winsize(int *width, int *height)
{
	struct winsize ws;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
		return (1);
	*width = ws.ws_col;
	*height = ws.ws_row;
	return (0);
}
