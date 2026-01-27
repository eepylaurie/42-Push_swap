/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 23:00:45 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/27 18:34:06 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b, int *values)
{
	if (values)
		free(values);
	if (a)
		stack_clear(a);
	if (b)
		stack_clear(b);
	write(2, "Error\n", 6);
	exit(1);
}
