/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:01:45 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 21:05:00 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	half_chunk(int chunk)
{
	return (chunk / 2);
}

void	push_chunks(t_stack *a, t_stack *b)
{
	int	n;
	int	chunk;
	int	limit;
	int	pushed;

	n = stack_len(a);
	chunk = chunk_size(n);
	limit = chunk;
	pushed = 0;
	while (pushed < n)
	{
		if (a->top->idx < limit)
		{
			pb(a, b);
			pushed++;
			if (b->top->idx < (limit - half_chunk(chunk)))
				rb(b);
			if (pushed == limit)
				limit += chunk;
		}
		else
			ra(a);
	}
}
