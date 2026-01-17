/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:13:23 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 18:19:46 by lmatthes         ###   ########.fr       */
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
