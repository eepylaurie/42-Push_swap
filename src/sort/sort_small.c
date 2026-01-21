/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:02:50 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/20 18:54:03 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->idx;
	y = a->top->next->idx;
	z = a->top->next->next->idx;
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		op_sa(a);
	else if (x > y && y > z)
	{
		op_sa(a);
		op_rra(a);
	}
	else if (x > y && y < z && x > z)
		op_ra(a);
	else if (x < y && y > z && x < z)
	{
		op_sa(a);
		op_ra(a);
	}
	else if (x < y && y > z && x > z)
		op_rra(a);
}

void	sort_small_five(t_stack *a, t_stack *b)
{
	int	len;

	len = stack_len(a);
	if (len == 4)
	{
		sort_bring_index_to_top_a(a, 0);
		op_pb(a, b);
		sort_small_three(a);
		op_pa(a, b);
		return ;
	}
	sort_bring_index_to_top_a(a, 0);
	op_pb(a, b);
	sort_bring_index_to_top_a(a, 1);
	op_pb(a, b);
	sort_small_three(a);
	if (b->top && b->top->next && b->top->idx < b->top->next->idx)
		op_sb(b);
	op_pa(a, b);
	op_pa(a, b);
}
