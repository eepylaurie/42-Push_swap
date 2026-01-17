/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:20:22 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 20:53:44 by lmatthes         ###   ########.fr       */
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
	t_stack	b;
	
	stack_init(&a);
	stack_init(&b);
	stack_push_top(&a, node_new(3));
	stack_push_top(&a, node_new(2));
	stack_push_top(&a, node_new(1));
	stack_push_top(&b, node_new(3));
	stack_push_top(&b, node_new(2));
	stack_push_top(&b, node_new(1));
	print_stack(&a);
	print_stack(&b);
	rra(&a);
	rrb(&b);
	print_stack(&a);
	print_stack(&b);
	rrr(&a, &b);
	print_stack(&a);
	print_stack(&b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
