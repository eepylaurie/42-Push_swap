/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_bring_to_top.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:36:26 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/20 00:06:40 by lmatthes         ###   ########.fr       */
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

void	sort_chunk_bring_index_to_top(t_stack *a, int target)
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
