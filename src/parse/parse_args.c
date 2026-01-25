/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:22:11 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/25 21:06:00 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	parse_one_arg_into_stack(const char *s, t_stack *a)
{
	size_t	i;
	size_t	token_start;
	int		ok;
	int		value;
	int		found_number;

	i = 0;
	found_number = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (!s[i])
			break ;
		token_start = i;
		while (s[i] && !ft_isspace(s[i]))
			i++;
		value = parse_atoi_strict_span(s + token_start, i - token_start, &ok);
		if (!ok)
			error_exit();
		stack_add_bottom(a, stack_node_new(value));
		found_number = 1;
	}
	return (found_number);
}

void	parse_args(int argc, char **argv, t_stack *a)
{
	int	i;
	int	found_any_number;
	int	count;
	int	*values;

	if (argc <= 1)
		return ;
	found_any_number = 0;
	i = 1;
	while (i < argc)
	{
		if (parse_one_arg_into_stack(argv[i], a))
			found_any_number = 1;
		i++;
	}
	if (!found_any_number)
		error_exit();
	values = stack_to_array(a, &count);
	parse_check_duplicates(values, count);
	free(values);
}
