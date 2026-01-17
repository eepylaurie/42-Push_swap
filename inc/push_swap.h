/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:43:32 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/17 18:04:42 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}	t_stack;

// function prototypes
void	stack_init(t_stack *s);
t_node	*node_new(int val);
void	stack_push_top(t_stack *s, t_node *n);
t_node	*stack_pop_top(t_stack *s);
void	stack_add_bottom(t_stack *s, t_node *n);

#endif