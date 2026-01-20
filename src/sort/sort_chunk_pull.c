/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_pull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:45:32 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/20 18:21:09 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk_pull(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->top)
	{
		pos = sort_find_pos_of_max_index(b);
		sort_bring_pos_to_top_b(b, pos);
		op_pa(a, b);
	}
}
