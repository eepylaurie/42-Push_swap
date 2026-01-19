/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_back_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:45:32 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 19:46:57 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pull_back_max(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->top)
	{
		pos = pos_of_max_index(b);
		bring_pos_to_top_b(b, pos);
		pa(a, b);
	}
}
