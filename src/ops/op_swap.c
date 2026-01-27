/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:43:34 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/27 23:25:57 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!s || s->size < 2)
		return (0);
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
	return (1);
}

void	op_sa(t_stack *a)
{
	if (op_swap(a))
		write(1, "sa\n", 3);
}

void	op_sb(t_stack *b)
{
	if (op_swap(b))
		write(1, "sb\n", 3);
}

void	op_ss(t_stack *a, t_stack *b)
{
	int	did_a;
	int	did_b;

	did_a = op_swap(a);
	did_b = op_swap(b);
	if (did_a || did_b)
		write(1, "ss\n", 3);
}
