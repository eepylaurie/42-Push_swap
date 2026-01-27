/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:43:32 by lmatthes          #+#    #+#             */
/*   Updated: 2026/01/27 23:43:17 by lmatthes         ###   ########.fr       */
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
t_node	*stack_node_new(int val);
void	stack_push_top(t_stack *s, t_node *n);
t_node	*stack_pop_top(t_stack *s);
void	stack_add_bottom(t_stack *s, t_node *n);
int		stack_is_sorted(t_stack *s);
void	stack_clear(t_stack *s);
void	stack_index(t_stack *a);
int		stack_len(t_stack *s);
int		*stack_to_array(t_stack *a, int *n);

// operations
int		op_swap(t_stack *s);
void	op_sa(t_stack *a);
void	op_sb(t_stack *b);
void	op_ss(t_stack *a, t_stack *b);

int		op_push(t_stack *src, t_stack *dst);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);

int		op_rotate(t_stack *s);
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rr(t_stack *a, t_stack *b);

int		op_rev_rotate(t_stack *s);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);

// parsing
int		parse_atoi_strict_span(const char *p, size_t len, int *ok);
void	parse_check_duplicates(int *arr, int n, t_stack *a);
void	parse_args(int argc, char **argv, t_stack *a);

// error
void	error_exit(t_stack *a, t_stack *b, int *values);

// sorting
void	sort_dispatch(t_stack *a, t_stack *b);
void	sort_small_three(t_stack *a);
void	sort_small_five(t_stack *a, t_stack *b);
void	sort_chunk(t_stack *a, t_stack *b);
void	sort_chunk_push(t_stack *a, t_stack *b);
void	sort_chunk_pull(t_stack *a, t_stack *b);
int		sort_find_pos_of_max_index(t_stack *s);
void	sort_bring_pos_to_top_a(t_stack *a, int pos);
void	sort_bring_pos_to_top_b(t_stack *b, int pos);
void	sort_bring_index_to_top_a(t_stack *a, int target);

#endif