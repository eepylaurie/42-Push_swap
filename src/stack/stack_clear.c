/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:23:04 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 18:32:07 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_stack *s)
{
	t_node	*tmp;

	if (!s)
		return ;
	while (s->top)
	{
		tmp = stack_pop_top(s);
		free(tmp);
	}
}
