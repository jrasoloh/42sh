/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:35:29 by echojnow          #+#    #+#             */
/*   Updated: 2018/06/15 16:06:16 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"
#include "line_edition.h"
#include <stdio.h>

int			test(int n)
{
	return (write(1, &n, 1));
}

int			event(char *c, t_caps *caps)
{
	FT_UNUSED(caps);
	if ((c[0] >= 'a' && c[0] <= 'z') || (c[0] >= 'A' && c[0] <= 'Z'))
		add_to_line(c[0]);
	else if (c[0] == TO_K_BAC || c[0] == TO_K_DEL)
	{
			del_last_char();
		//	printf(" un caractere supp\n");
	}


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

int	edit_loop()
{
	int		running;
	char	c[3];
	t_caps	*caps;

	running = 1;
	ft_memset(&c, 0, TO_READ_SIZE);
	caps = save_caps(NULL);
	init_edit();
	print_line();
	while (running)
	{
		read(0, &c, TO_READ_SIZE);

//		 if ((running = event(c)) == 1)
//			return (1);
		running = event(&c[0], caps);
		tputs(tgetstr("cr", NULL), 1, &test);
		tputs(tgetstr("cd", NULL), 1, &test);
		print_line();
		ft_memset(&c, 0, TO_READ_SIZE);
	}
	return (0);
}
