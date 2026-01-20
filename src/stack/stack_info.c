/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:50:59 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/20 14:06:08 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stack *s)
{
	t_node	*cur;

	if (!s || s->size < 2)
		return (1);
	cur = s->top;
	while (cur->next)
	{
		if (cur->val > cur->next->val)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	stack_len(t_stack *s)
{
	int		len;
	t_node	*cur;

	len = 0;
	cur = s->top;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return (len);
}
