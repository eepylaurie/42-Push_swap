/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:20:22 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 15:24:29 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	a;

	a.head = (void *)1;
	a.tail = (void *)1;
	a.size = 123;
	stack_init(&a);
	printf("head=%p tail=%p size=%d\n", (void *)a.head, (void *)a.tail, a.size);
	return (0);
}
