/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_pullback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:45:32 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 22:55:39 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk_pullback(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->top)
	{
		pos = sort_chunk_pos_of_max_index(b);
		sort_chunk_bring_pos_to_top_b(b, pos);
		op_pa(a, b);
	}
}
