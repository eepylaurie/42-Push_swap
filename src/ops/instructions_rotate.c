/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:14:50 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 20:18:48 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_rotate(t_stack *s)
{
	t_node	*n;

	if (!s || s->size < 2)
		return ;
	n = stack_pop_top(s);
	stack_add_bottom(s, n);
}