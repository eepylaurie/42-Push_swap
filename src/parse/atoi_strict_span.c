/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_strict_span.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:48:08 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/18 20:19:17 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static long long	get_sign(const char *p, size_t len, size_t *i, int *ok)
{
	long long	sign;

	sign = 1;
	if (*i < len && (p[*i] == '+' || p[*i] == '-'))
	{
		if (p[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (*i >= len)
		*ok = 0;
	return (sign);
}

static int	accumulate_digit(long long *res, long long sign, char c)
{
	*res = (*res * 10) + (c - '0');
	if (sign * (*res) > INT_MAX || sign * (*res) < INT_MIN)
		return (0);
	return (1);
}

static int	parse_digits(const char *p, size_t len, size_t i, long long sign)
{
	long long	res;

	if (i >= len || !ft_isdigit(p[i]))
		return (0);
	res = 0;
	while (i < len)
	{
		if (!ft_isdigit(p[i]))
			return (0);
		if (!accumulate_digit(&res, sign, p[i]))
			return (0);
		i++;
	}
	return ((int)(sign * res));
}

int	atoi_strict_span(const char *p, size_t len, int *ok)
{
	size_t		i;
	long long	sign;
	int			val;

	*ok = 1;
	if (!p || len == 0)
	{
		*ok = 0;
		return (0);
	}
	i = 0;
	sign = get_sign(p, len, &i, ok);
	if (*ok == 0)
		return (0);
	val = parse_digits(p, len, i, sign);
	if (val == 0 && !(len == 1 && p[0] == '0') && !(len == 2
			&& (p[0] == '+' || p[0] == '-') && p[1] == '0'))
	{
		*ok = 0;
		return (0);
	}
	return (val);
}
