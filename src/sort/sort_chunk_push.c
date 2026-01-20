/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:01:45 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/20 17:25:24 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_calc_chunk_size(int n)
{
	if (n <= 100)
		return (20);
	return (45);
}

static int	sort_half_chunk(int chunk)
{
	return (chunk / 2);
}

void	sort_chunk_push(t_stack *a, t_stack *b)
{
	int	n;
	int	chunk;
	int	limit;
	int	pushed;

	n = stack_len(a);
	chunk = sort_calc_chunk_size(n);
	limit = chunk;
	pushed = 0;
	while (pushed < n)
	{
		if (a->top->idx < limit)
		{
			op_pb(a, b);
			pushed++;
			if (b->top->idx < (limit - sort_half_chunk(chunk)))
				op_rb(b);
			if (pushed == limit)
				limit += chunk;
		}
		else
			op_ra(a);
	}
}
