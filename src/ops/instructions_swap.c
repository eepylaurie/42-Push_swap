/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:43:34 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 19:35:54 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_swap(t_stack *s)
{
	t_node *first;
	t_node *second;
	t_node *third;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	else
		s->bot = first;
	s->top = second;
}

void	sa(t_stack *a)
{
	op_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	op_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	op_swap(a);
	op_swap(b);
	write(1, "ss\n", 3);
}
