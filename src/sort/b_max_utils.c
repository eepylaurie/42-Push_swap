/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_max_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:24:48 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 19:29:24 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_of_max_index(t_stack *b)
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

void	bring_pos_to_top_b(t_stack *b, int pos)
{
	int	len;

	len = stack_len(b);
	if (len < 2 || pos < 0 || pos >= len)
		return ;
	if (pos <= len / 2)
		while (pos-- > 0)
			rb(b);
	else
		while (pos++ < len)
			rrb(b);
}
