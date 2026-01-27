/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_atoi_strict_span.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:48:08 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/28 00:10:59 by lmatthes         ###   ########.fr       */
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

static int	accumulate_digit(long long *res, int digit)
{
	if (*res > (LLONG_MAX - digit) / 10)
		return (0);
	*res = (*res * 10) + digit;
	return (1);
}

static int	parse_digits(t_atoi_ctx *ctx)
{
	long long	res;
	long long	limit;

	if (ctx->i >= ctx->len || !ft_isdigit(ctx->p[ctx->i]))
		return (*(ctx->ok) = 0, 0);
	res = 0;
	while (ctx->i < ctx->len)
	{
		if (!ft_isdigit(ctx->p[ctx->i]))
			return (*(ctx->ok) = 0, 0);
		if (!accumulate_digit(&res, ctx->p[ctx->i] - '0'))
			return (*(ctx->ok) = 0, 0);
		ctx->i++;
	}
	limit = (long long)INT_MAX;
	if (ctx->sign < 0)
		limit = -(long long)INT_MIN;
	if (res > limit)
		return (*(ctx->ok) = 0, 0);
	return ((int)(ctx->sign * res));
}

int	parse_atoi_strict_span(const char *p, size_t len, int *ok)
{
	t_atoi_ctx	ctx;

	*ok = 1;
	if (!p || len == 0)
	{
		*ok = 0;
		return (0);
	}
	ctx.p = p;
	ctx.len = len;
	ctx.i = 0;
	ctx.ok = ok;
	ctx.sign = get_sign(p, len, &ctx.i, ok);
	if (*ok == 0)
		return (0);
	return (parse_digits(&ctx));
}
