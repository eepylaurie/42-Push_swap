/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:44:48 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 17:51:52 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_pop_top(t_stack *s)
{
	t_node	*n;

	if (!s || !s->top)
		return (NULL);
	n = s->top;
	s->top = n->next;
	if (s->top)
		s->top->prev = NULL;
	else
		s->bot = NULL;
	n->next = NULL;
	n->prev = NULL;
	s->size--;
	return (n);
}
