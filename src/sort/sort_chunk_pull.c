/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_pull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:45:32 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/20 17:29:43 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_find_pos_of_max_index_b(t_stack *b)
{
	int		pos;
	int		best_pos;
	int		best_idx;
	t_node	*cur;

	pos = 0;
	best_pos = 0;
	best_idx = -1;
	cur = b->top;
	while (cur)
	{
		if (cur->idx > best_idx)
		{
			best_idx = cur->idx;
			best_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (best_pos);
}

static void	sort_bring_pos_to_top_b(t_stack *b, int pos)
{
	int	len;
	int	r;

	len = stack_len(b);
	if (len < 2 || pos < 0 || pos >= len)
		return ;
	if (pos <= len / 2)
		while (pos-- > 0)
			op_rb(b);
	else
	{
		r = len - pos;
		while (r-- > 0)
			op_rrb(b);
	}
}

void	sort_chunk_pull(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->top)
	{
		pos = sort_find_pos_of_max_index_b(b);
		sort_bring_pos_to_top_b(b, pos);
		op_pa(a, b);
	}
}
