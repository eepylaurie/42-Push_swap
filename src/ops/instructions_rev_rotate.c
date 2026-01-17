/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rev_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:36:11 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 20:51:56 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_rev_rotate(t_stack *s)
{
	t_node	*last;

	if (!s || s->size < 2)
		return ;
	last = s->bot;
	s->bot = last->prev;
	s->bot->next = NULL;
	last->prev = NULL;
	last->next = s->top;
	s->top->prev = last;
	s->top = last;
}

void	rra(t_stack *a)
{
	op_rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	op_rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	op_rev_rotate(a);
	op_rev_rotate(b);
	write(1, "rrr\n", 4);
}
