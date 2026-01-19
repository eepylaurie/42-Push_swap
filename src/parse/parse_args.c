/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:22:11 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 22:52:07 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	scan_one_arg(const char *s, t_stack *a)
{
	size_t	j;
	size_t	start;
	int		ok;
	int		val;
	int		found;

	j = 0;
	found = 0;
	while (s[j])
	{
		while (s[j] && ft_isspace(s[j]))
			j++;
		if (!s[j])
			break ;
		start = j;
		while (s[j] && !ft_isspace(s[j]))
			j++;
		val = parse_atoi_strict_span(s + start, j - start, &ok);
		if (!ok)
			error_exit();
		stack_add_bottom(a, stack_node_new(val));
		found = 1;
	}
	return (found);
}

void	parse_args(int argc, char **argv, t_stack *a)
{
	int	i;
	int	found_any;
	int	n;
	int	*arr;

	if (argc == 1)
		return ;
	i = 1;
	found_any = 0;
	while (i < argc)
	{
		if (scan_one_arg(argv[i], a))
			found_any = 1;
		i++;
	}
	if (!found_any)
		error_exit();
	arr = stack_to_array(a, &n);
	parse_check_duplicates(arr, n);
	free(arr);
}
