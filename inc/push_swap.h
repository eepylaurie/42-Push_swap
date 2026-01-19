/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:43:32 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/19 16:35:03 by lmatthes         ###   ########.fr       */
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

// stack functions
void	stack_init(t_stack *s);
t_node	*node_new(int val);
void	stack_push_top(t_stack *s, t_node *n);
t_node	*stack_pop_top(t_stack *s);
void	stack_add_bottom(t_stack *s, t_node *n);
int		stack_is_sorted(t_stack *s);
void	stack_clear(t_stack *s);
int		is_sorted(t_stack *a);
void	index_stack(t_stack *a);

// swap instructions
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// push instructions
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// rotate instructions
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// reverse rotate instructions
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// parsing
int		atoi_strict(const char *s, int *ok);
int		atoi_strict_span(const char *p, size_t len, int *ok);
void	check_duplicates(const int *arr, int n);
int		*stack_to_array(t_stack *a, int *n);
void	parse_args(int argc, char **argv, t_stack *a);

// error
void	error_exit(void);

#endif