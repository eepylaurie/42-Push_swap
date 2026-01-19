/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:20:22 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 23:06:12 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);
	parse_args(argc, argv, &a);
	if (stack_is_sorted(&a))
		return (0);
	stack_index(&a);
	if (stack_len(&a) <= 3)
		sort_small_three(&a);
	else if (stack_len(&a) <= 5)
		sort_small_five(&a, &b);
	else
		sort_chunk(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
