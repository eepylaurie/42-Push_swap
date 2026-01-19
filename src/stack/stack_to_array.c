/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:52:44 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 15:56:51 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *a, int *n)
{
	int		*arr;
	int		i;
	t_node	*cur;

	*n = 0;
	cur = a->top;
	while (cur)
	{
		(*n)++;
		cur = cur->next;
	}
	arr = (int *)malloc(sizeof(int) * (*n));
	if (!arr)
		error_exit();
	i = 0;
	cur = a->top;
	while (cur)
	{
		arr[i] = cur->val;
		i++;
		cur = cur->next;
	}
	return (arr);
}
