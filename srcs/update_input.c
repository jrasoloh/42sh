/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:08:59 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/22 12:05:20 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

static void	replace(int change_i, char **s, char *w, int var_len)
{
	size_t	w_len;
	char	*cpy;
	int		ci;
	int		si;

	w_len = ft_strlen(w);
	cpy = ft_strdup(*s);
	free(*s);
	*s = ft_strnew((ft_strlen(cpy) - 1) + w_len);
	ci = -1;
	si = -1;
	while (cpy[++ci])
	{
		si++;
		if (ci != change_i)
			(*s)[si] = cpy[ci];
		else
		{
			ci += ((var_len > 1) ? var_len : 0);
			si += w_len - 1;
			ft_strcat(*s, w);
		}
	}
	free(cpy);
}

static int	get_var_len(char *s, int i)
{
	int	i_cpy;

	i_cpy = i;
	while (s[i] && !(s[i] <= ' ')
			&& ((s[i] >= 'a' && s[i] <= 'z')
				|| (s[i] >= 'A' && s[i] <= 'Z')
				|| (s[i] == '_')))
		i++;
	return (i - i_cpy);
}

static void	clean_backslahes(char **input)
{
	int		l;
	int		c;
	char	*cpy;

	l = -1;
	while (input[++l])
	{
		c = -1;
		while (input[l][++c])
		{
			if (input[l][c] == '\\'
					&& ((c > 0 && input[l][c - 1] != '\\') || (c == 0)))
			{
				cpy = input[l];
				input[l] = ft_strrm(input[l], c, 1);
				free(cpy);
			}
		}
	}
}

void		update_input(char **input, char **env)
{
	int		l;
	int		c;
	char	*var;

	l = -1;
	while (input[++l])
	{
		c = -1;
		while (input[l][++c])
		{
			if (input[l][c] == '~' && !(c > 0 && input[l][c - 1] == '\\'))
			{
				if (get_val(env, "HOME") != NULL)
					replace(c, &input[l], get_val(env, "HOME"), 1);
			}
			else if (input[l][c] == '$' && !(c > 0 && input[l][c - 1] == '\\'))
			{
				var = ft_strsub(input[l], c + 1, get_var_len(input[l], c + 1));
				if (get_val(env, var) != NULL)
					replace(c, &input[l], get_val(env, var), ft_strlen(var));
				free(var);
			}
		}
	}
	clean_backslahes(input);
}
