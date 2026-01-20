/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:39:50 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/20 16:56:08 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pos_of_index(t_stack *a, int target)
{
	int		pos;
	t_node	*cur;

	pos = 0;
	cur = a->top;
	while (cur)
	{
		if (cur->idx == target)
			return (pos);
		pos++;
		cur = cur->next;
	}
	return (-1);
}

void	sort_bring_index_to_top(t_stack *a, int target)
{
	int	pos;
	int	len;

	pos = pos_of_index(a, target);
	len = stack_len(a);
	if (pos < 0)
		return ;
	if (pos <= len / 2)
		while (pos-- > 0)
			op_ra(a);
	else
		while (pos++ < len)
			op_rra(a);
}

int	sort_chunk_pos_of_max_index(t_stack *b)
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

void	sort_chunk_bring_pos_to_top_b(t_stack *b, int pos)
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
