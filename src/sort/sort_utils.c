/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:39:50 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/20 17:30:03 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_find_pos_of_index_a(t_stack *a, int index)
{
	int		pos;
	t_node	*cur;

	pos = 0;
	cur = a->top;
	while (cur)
	{
		if (cur->idx == index)
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

	pos = sort_find_pos_of_index_a(a, target);
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
