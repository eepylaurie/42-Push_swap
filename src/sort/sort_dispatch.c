/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:11:32 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/21 16:14:40 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dispatch(t_stack *a, t_stack *b)
{
	int	len;

	stack_index(a);
	len = stack_len(a);
	if (len == 2)
	{
		if (a->top->idx > a->top->next->idx)
			op_sa(a);
	}
	else if (len == 3)
		sort_small_three(a);
	else if (len <= 5)
		sort_small_five(a, b);
	else
		sort_chunk(a, b);
}
