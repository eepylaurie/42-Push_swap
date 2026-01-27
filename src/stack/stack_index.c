/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:35:46 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/27 20:46:24 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort_int_array(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (arr[j] > arr[j + 1])
				swap_int(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

static int	find_pos(const int *arr, int n, int v)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == v)
			return (i);
		i++;
	}
	return (-1);
}

void	stack_index(t_stack *a)
{
	int		*arr;
	int		n;
	int		pos;
	t_node	*cur;

	arr = stack_to_array(a, &n);
	if (!arr)
		error_exit(a, NULL, NULL);
	sort_int_array(arr, n);
	cur = a->top;
	while (cur)
	{
		pos = find_pos(arr, n, cur->val);
		cur->idx = pos;
		cur = cur->next;
	}
	free(arr);
}
