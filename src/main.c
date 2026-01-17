/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:20:22 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 21:52:15 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	test(const char *s)
{
	int	ok;
	int	v;

	v = atoi_strict(s, &ok);
	printf("input: %-12s | ok=%d | val=%d\n",
		s ? s : "NULL", ok, v);
}

int	main(void)
{
	test("0");
	test("42");
	test("+42");
	test("-42");
	test("0042");
	test("2147483647");
	test("-2147483648");
	test("");
	test("+");
	test("-");
	test("++1");
	test("--1");
	test("42a");
	test("a42");
	test("2147483648");
	test("-2147483649");
	test("1 2");
	test(" ");
	return (0);
}
