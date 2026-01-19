/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:42:31 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 22:20:07 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_push(t_stack *src, t_stack *dst)
{
	t_node	*n;

	if (!src || src->size == 0)
		return ;
	n = stack_pop_top(src);
	stack_push_top(dst, n);
}

void	op_pa(t_stack *a, t_stack *b)
{
	op_push(b, a);
	write(1, "pa\n", 3);
}

void	op_pb(t_stack *a, t_stack *b)
{
	op_push(a, b);
	write(1, "pb\n", 3);
}
