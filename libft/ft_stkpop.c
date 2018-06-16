/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:41:57 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/20 16:45:46 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*ft_stkpop(t_stack **stack, void (*del)(void **data))
{
	t_stack	*cpy;

	if (stack == NULL || *stack == NULL)
		return (NULL);
	del(&(*stack)->data);
	cpy = *stack;
	*stack = (*stack)->next;
	free(cpy);
	return (*stack);
}
