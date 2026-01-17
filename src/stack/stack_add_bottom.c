/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:55:48 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 18:04:38 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
