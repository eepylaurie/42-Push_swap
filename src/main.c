/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:20:22 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 20:52:51 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_stack_indexes(t_stack *s, char name)
{
	t_node	*cur;

	printf("Stack %c: ", name);
	cur = s->top;
	while (cur)
	{
		printf("%d ", cur->idx);
		cur = cur->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);
	parse_args(argc, argv, &a);
	// if (is_sorted(&a))
	// 	return (0);
	index_stack(&a);
	while (stack_len(&a) > 0)
		pb(&a, &b);
	print_stack_indexes(&a, 'A');
	print_stack_indexes(&b, 'B');
	pull_back_max(&a, &b);
	print_stack_indexes(&a, 'A');
	print_stack_indexes(&b, 'B');
	// pos = pos_of_max_index(&b);
	// bring_pos_to_top_b(&b, pos);
	// if (b.top)
	// 	printf("B top index = %d\n", b.top->idx);
	// if (stack_len(&a) <= 3)
	// 	sort_three(&a);
	// else if (stack_len(&a) <= 5)
	// 	sort_five(&a, &b);
	// else
	// 	chunk_sort(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
