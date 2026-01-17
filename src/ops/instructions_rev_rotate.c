/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rev_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:36:11 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 20:49:18 by lmatthes         ###   ########.fr       */
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
