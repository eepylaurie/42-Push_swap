/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:20:22 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/18 20:17:34 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	test_one(const char *p, size_t len)
{
	int	ok;
	int	v;

	v = atoi_strict_span(p, len, &ok);
	printf("span='%.*s' len=%zu -> ok=%d, v=%d\n",
		(int)len, p, len, ok, v);
}

int	main(void)
{
	test_one("6", 1);
	test_one("-2", 2);
	test_one("+0", 2);
	test_one("0", 1);
	test_one("+", 1);
	test_one(" 3", 2);
	test_one("3 ", 2);
	test_one("6 3", 3);
	test_one("2147483647", 10);
	test_one("2147483648", 10);
	test_one("-2147483648", 11);
	test_one("-2147483649", 11);
	test_one("--3", 3);
	test_one("3-2", 3);
	return (0);
}
