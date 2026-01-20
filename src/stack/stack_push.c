/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:24:13 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/20 14:18:27 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push_top(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	n->prev = NULL;
	n->next = s->top;
	if (s->top)
		s->top->prev = n;
	else
		s->bot = n;
	s->top = n;
	s->size++;
}

void	stack_add_bottom(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	n->next = NULL;
	n->prev = s->bot;
	if (s->bot)
		s->bot->next = n;
	else
		s->top = n;
	s->bot = n;
	s->size++;
}
