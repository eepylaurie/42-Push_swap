/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:20:22 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 23:11:17 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	int	a1[] = {3, 2, 1};
	int	a2[] = {3, 2, 3};

	printf("Testing a1 (no duplicates)...\n");
	check_duplicates(a1, 3);
	printf("a1 OK\n");
	printf("Testing a2 (with duplicates)...\n");
	check_duplicates(a2, 3);
	printf("a2 OK (SHOULD NOT PRINT)\n");
	return (0);
}
