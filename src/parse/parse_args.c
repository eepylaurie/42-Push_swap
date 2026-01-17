/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 23:18:56 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 23:38:37 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_tokens(char **toks)
{
	int	i;

	i = 0;
	while (toks[i])
		i++;
	return (i);
}

static int	*tokens_to_ints(char **toks, int n)
{
	int	*vals;
	int	i;
	int	ok;

	vals = (int *)malloc(sizeof(int) * n);
	if (!vals)
		error_exit();
	i = 0;
	while (i < n)
	{
		vals[i] = atoi_strict(toks[i], &ok);
		if (!ok)
			error_exit();
		i++;
	}
	return (vals);
}

static void	build_stack_from_ints(t_stack *a, const int *vals, int n)
{
	int		i;
	t_node	*node;

	i = 0;
	while (i < n)
	{
		node = node_new(vals[i]);
		if (!node)
			error_exit();
		stack_add_bottom(a, node);
		i++;
	}
}

void	parse_args(int argc, char **argv, t_stack *a)
{
	char	**toks;
	int		*vals;
	int		n;

	toks = split_args(argc, argv);
	if (!toks)
		error_exit();
	n = count_tokens(toks);
	if (n == 0)
		error_exit();
	vals = tokens_to_ints(toks, n);
	check_duplicates(vals, n);
	build_stack_from_ints(a, vals, n);
	free(vals);
	free_split(toks);
}
