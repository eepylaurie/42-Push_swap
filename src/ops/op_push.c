/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:42:31 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/27 23:29:09 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_push(t_stack *src, t_stack *dst)
{
	t_node	*n;

	if (!src || !dst || src->size == 0)
		return (0);
	n = stack_pop_top(src);
	stack_push_top(dst, n);
	return (1);
}

void	op_pa(t_stack *a, t_stack *b)
{
	if (op_push(b, a))
		write(1, "pa\n", 3);
}

void	op_pb(t_stack *a, t_stack *b)
{
	if (op_push(a, b))
		write(1, "pb\n", 3);
}
