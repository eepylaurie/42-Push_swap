/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:11:08 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 23:01:44 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_five(t_stack *a, t_stack *b)
{
	int	len;

	len = stack_len(a);
	if (len == 4)
	{
		sort_chunk_bring_index_to_top(a, 0);
		op_pb(a, b);
		sort_small_three(a);
		op_pa(a, b);
		return ;
	}
	sort_chunk_bring_index_to_top(a, 0);
	op_pb(a, b);
	sort_chunk_bring_index_to_top(a, 1);
	op_pb(a, b);
	sort_small_three(a);
	op_pa(a, b);
	op_pa(a, b);
}
