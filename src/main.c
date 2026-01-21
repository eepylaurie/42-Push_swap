/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:20:22 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/21 16:15:53 by lmatthes         ###   ########.fr       */
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
	if (stack_len(&a) < 2 || stack_is_sorted(&a))
	{
		stack_clear(&a);
		stack_clear(&b);
		return (0);
	}
	sort_dispatch(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
