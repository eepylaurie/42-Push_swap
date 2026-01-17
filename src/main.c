/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:20:22 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 16:54:53 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	a;
	t_node	*n;

	stack_init(&a);
	n = node_new(42);
	if (!n)
		return (1);
	printf("node=%p value=%d index=%d next=%p prev=%p\n",
		(void *)n, n->value, n->index, (void *)n->next, (void *)n->prev);
	free(n);
	return (0);
}
