/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:45:15 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 17:23:01 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int val)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->val = val;
	n->idx = -1;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}
