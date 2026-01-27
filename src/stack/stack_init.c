/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:15:12 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/27 18:27:52 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s)
{
	if (!s)
		return ;
	s->top = NULL;
	s->bot = NULL;
	s->size = 0;
}

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
	s->top = NULL;
	s->bot = NULL;
	s->size = 0;
}
