/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:36:11 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/27 23:36:30 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_rev_rotate(t_stack *s)
{
	t_node	*last;

	if (!s || s->size < 2)
		return (0);
	last = s->bot;
	s->bot = last->prev;
	s->bot->next = NULL;
	last->prev = NULL;
	last->next = s->top;
	s->top->prev = last;
	s->top = last;
	return (1);
}

void	op_rra(t_stack *a)
{
	if (op_rev_rotate(a))
		write(1, "rra\n", 4);
}

void	op_rrb(t_stack *b)
{
	if (op_rev_rotate(b))
		write(1, "rrb\n", 4);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	int	did_a;
	int	did_b;

	did_a = op_rev_rotate(a);
	did_b = op_rev_rotate(b);
	if (did_a || did_b)
		write(1, "rrr\n", 4);
}
