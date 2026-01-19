/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:20:22 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 16:47:57 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);
	parse_args(argc, argv, &a);
	index_stack(&a);
	t_node	*cur = a.top;
	while (cur)
	{
		printf("value=%d index=%d\n", cur->val, cur->idx);
		cur = cur->next;
	}
	// if (is_sorted(&a))
	// {
	// 	write(1, "SORTED\n", 7);
	// 	stack_clear(&a);
	// 	stack_clear(&b);
	// 	return (0);
	// }
	// write(1, "NOT SORTED\n", 11);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
