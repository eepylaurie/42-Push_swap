/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_strict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:04:07 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 21:34:31 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_sign(const char *s, int *i, long long *sign)
{
	*sign = 1;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (s[*i] < '0' || s[*i] > '9')
		return (0);
	return (1);
}

int	atoi_strict(const char *s, int *ok)
{
	long long	res;
	long long	sign;
	int			i;

	*ok = 0;
	if (!s || !s[0])
		return (0);
	i = 0;
	res = 0;
	if (!parse_sign(s, &i, &sign))
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		res = res * 10 + (s[i++] - '0');
		if (sign * res > INT_MAX || sign * res < INT_MIN)
			return (0);
	}
	*ok = 1;
	return ((int)(sign * res));
}
