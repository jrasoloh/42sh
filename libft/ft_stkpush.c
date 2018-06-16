/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:31:40 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/20 16:41:13 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*ft_stkpush(t_stack **stack, void *data)
{
	t_stack	*new;

	if (stack == NULL)
		return (NULL);
	if (*stack == NULL)
	{
		if ((new = (t_stack*)malloc(sizeof(t_stack))) == NULL)
			return (NULL);
		*stack = new;
	}
	new->data = data;
	new->next = *stack;
	return (new);
}
