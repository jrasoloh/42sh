/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:35:29 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/25 17:00:32 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"
#include <stdio.h>

int					event(char *c, t_caps *caps)
{
	t_line			*crs;

	FT_UNUSED(caps);
	crs = g_edit->cursor;
	if (!ft_strncmp(TO_K_CTRL_UP, c, 7))
		move_up();
	else if (c[0] == 16 && c[1] == 0)
	{
		g_edit->mode = (g_edit->mode == 0) ?
			enter_selection_mode() : exit_selection_mode();
	}
	else if (c[0] == 11 && c[1] == 0)
	{
		if (g_edit->mode == 1)
			delete_selection();
		else
			paste_selection();
	}
	else if (!ft_strncmp(TO_K_CTRL_DOWN, c, 7))
		move_down();
	else if (!ft_strcmp(c, TO_K_LEFT))
		move_left();
	else if (!ft_strcmp(c, TO_K_RIGHT))
		move_right();
	else if (!ft_strncmp(c, TO_K_SHIFT_LEFT, 7))
		go_to_previous_word();
	else if (!ft_strncmp(c, TO_K_SHIFT_RIGHT, 7))
		go_to_next_word();
	else if (!ft_strcmp(c, TO_K_HOME))
		go_to_head();
	else if (!ft_strcmp(c, TO_K_END))
		go_to_tail();
	else if (!ft_strcmp(c, TO_K_DEL_FWD))
		del_next_char();
	else if (c[0] == TO_K_BAC || c[0] == TO_K_DEL)
		del_last_char();
	else if (c[0] == TO_K_RET)
	{
		int return_eval = eval_line();
		if (return_eval > 0)
			add_return_to_line(return_eval);
		else
			return (0);
	}
	else if (ft_is_printable(c[0]) || ft_isblank(c[0]))
		add_to_line(c[0]);


		/* ft_putstr(caps->ins); */
		/* ft_putstr(caps->cin); */
		/* ft_putstr("=:z:"); */
		/* ft_putstr(caps->qin); */
		/* ft_put(":%s=z:", caps->cin); */
		/* tputs(caps->cin, 0, &test); */
		/* ft_putmem_fd(caps->cin, 10, 0, 0); */

		/* int i = 0; */
		/* while (caps->cin[i]) */
		/* { */
			/* ft_put("%d\n\t", caps->cin[i++]); */
			/* i++; */
		/* } */

		/* ft_put("TEST: %c\n\t", caps->cin[0]); */
//	}
/*	else if (c[0] == TO_K_ESC && c[1] == '[')
	{
		if (c[2] == 'A')
		{
	//		ft_putstr(caps->up);
			ft_put("up");
		}
		else if (c[2] == 'B')
		{
	//		ft_putstr(caps->dwn);
			ft_put("down");
		}
		else if (c[2] == 'D') // left
		{
			ft_putstr(caps->lft);
		}
		else if (c[2] == 'C') // right
		{
			ft_putstr(caps->rgt);
		}
	}
	else if (c[0] == TO_K_SPA)
	{
	}
	else if (c[0] == TO_K_RET)
		return (2);
	if (c[0] == TO_K_ESC && c[1] != '[')
		return (0);
	else if (c[0] == TO_K_BAC || c[0] == TO_K_DEL)
	{
	}*/
	return (1);
}

int				edit_loop()
{
	int			running;
	char		c[7];
	t_caps		*caps;
	int			i;

	running = 1;
	ft_memset(&c, 0, TO_READ_SIZE);
	caps = save_caps(NULL);
	init_edit();
	print_line();
	i = get_line_number();
	while (running)
	{
		read(0, &c, TO_READ_SIZE);
		/* ft_putnbr(c[0]); */
		/* ft_putchar('\n'); */
		/* ft_putnbr(c[1]); */
		/* ft_putchar('\n'); */
		/* ft_putnbr(c[2]); */
		/* ft_putchar('\n'); */
		/* ft_putnbr(c[3]); */
		/* ft_putchar('\n'); */
		/* ft_putnbr(c[4]); */
		/* ft_putchar('\n'); */
		/* ft_putnbr(c[5]); */
		/* ft_putchar('\n'); */
		/* ft_putnbr(c[6]); */
		/* ft_putchar('\n'); */
		running = event(&c[0], caps);
		update_onscreen(i);
		i = get_line_number();
		ft_memset(&c, 0, TO_READ_SIZE);
	}
	return (0);
}
