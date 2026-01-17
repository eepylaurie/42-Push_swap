/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:20:22 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 17:32:53 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack *s)
{
	t_node *cur = s->top;

	printf("size= %d top=%d bot=%d | ", s->size,
		s->top ? s->top->val : -999,
		s->bot ? s->bot->val : -999);
	while (cur)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	a;

	stack_init(&a);
	stack_push_top(&a, node_new(3));
	stack_push_top(&a, node_new(2));
	stack_push_top(&a, node_new(1));
	print_stack(&a);
	return (0);
}
