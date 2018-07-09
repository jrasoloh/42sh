/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:57:07 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/21 18:16:11 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

static void	sigint_handler(int sig)
{
	/* char *pwd; */

	/* FT_UNUSED(sig); */
	/* pwd = save_pwd(NULL); */
	/* ft_putchar('\n'); */
	/* ft_put(TO_PROMPT, pwd); */

	FT_UNUSED(sig);
	ft_put("exiting...\r\n");
	exit_term();
}

static void	sigwinch_handler(int sig)
{
	FT_UNUSED(sig);
	// UNIMPLEMENTED
}

static void	sigstp_handler(int sig)
{
	struct termios	*orig_termios;
	char			cp[2];

	FT_UNUSED(sig);
	orig_termios = save_orig_termios(NULL);
	cp[0] = orig_termios->c_cc[VSUSP];
	cp[1] = '\0';
	restore_term();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDIN_FILENO, TIOCSTI, cp);
}

static void	sigcont_handler(int sig)
{
	t_caps	*caps;

	FT_UNUSED(sig);
	caps = save_caps(NULL);
	configure_term();
	signal(SIGTSTP, &sigstp_handler);
}

void		register_signals(void)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (i != SIGWINCH && i != SIGTSTP && i != SIGCONT && i != SIGINT
				&& i != SIGSEGV)
			signal(i, &sigint_handler);
	}
	signal(SIGINT, &sigint_handler);
	signal(SIGWINCH, &sigwinch_handler);
	signal(SIGTSTP, &sigstp_handler);
	signal(SIGCONT, &sigcont_handler);
}
