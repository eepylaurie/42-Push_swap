/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:14:50 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 20:29:03 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_rotate(t_stack *s)
{
	t_node	*n;

	if (!s || s->size < 2)
		return ;
	n = stack_pop_top(s);
	stack_add_bottom(s, n);
}

void	ra(t_stack *a)
{
	op_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	op_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	op_rotate(a);
	op_rotate(b);
	write(1, "rr\n", 3);
}
