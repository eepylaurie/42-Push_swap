/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:14:50 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/27 23:42:57 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_rotate(t_stack *s)
{
	t_node	*n;

	if (!s || s->size < 2)
		return (0);
	n = stack_pop_top(s);
	if (!n)
		return (0);
	stack_add_bottom(s, n);
	return (1);
}

void	op_ra(t_stack *a)
{
	if (op_rotate(a))
		write(1, "ra\n", 3);
}

void	op_rb(t_stack *b)
{
	if (op_rotate(b))
		write(1, "rb\n", 3);
}

void	op_rr(t_stack *a, t_stack *b)
{
	int	did_a;
	int	did_b;

	did_a = op_rotate(a);
	did_b = op_rotate(b);
	if (did_a || did_b)
		write(1, "rr\n", 3);
}
