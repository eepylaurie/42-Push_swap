/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:11:08 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 19:15:11 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *a, t_stack *b)
{
	int	len;

	len = stack_len(a);
	if (len == 4)
	{
		bring_index_to_top(a, 0);
		pb(a, b);
		sort_three(a);
		pa(a, b);
		return ;
	}
	bring_index_to_top(a, 0);
	pb(a, b);
	bring_index_to_top(a, 1);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
