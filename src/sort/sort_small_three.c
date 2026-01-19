/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:02:50 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 22:59:53 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	last_index(t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur->next)
		cur = cur->next;
	return (cur->idx);
}

void	sort_small_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->idx;
	y = a->top->next->idx;
	z = last_index(a);
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
