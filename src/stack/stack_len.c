/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:05:45 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 19:07:00 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *s)
{
	int		len;
	t_node	*cur;

	len = 0;
	cur = s->top;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return (len);
}
