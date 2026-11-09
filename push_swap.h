/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 push_swap.h										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 13:46:18 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 13:46:18 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ops_list
{
	char				*op;
	struct s_ops_list	*next;
}	t_ops_list;

typedef struct s_ops
{
	t_ops_list	*ops_list;
	int			sa_count;
	int			sb_count;
	int			ss_count;
	int			pa_count;
	int			pb_count;
	int			ra_count;
	int			rb_count;
	int			rr_count;
	int			rra_count;
	int			rrb_count;
	int			rrr_count;
	int			total;
}	t_ops;

//valication.c
void		validate_int(int value, char *values);
void		check_duplicate(int value, t_stack *stack);
void		raise_error(void);
int			get_option(int argc, char *argv[]);
//list_functions.c
t_stack		*stack_new(int n);
t_stack		*stack_penultimate(t_stack *stack);
t_stack		*stack_last(t_stack *stack);
size_t		get_input_stack_len(int argc, char *argv[]);
t_stack		*stack_init(int argc, char *argv[]);
//push_swap_pop.c
void		push(t_stack **stack, int n);
void		pop(t_stack **stack);
void		push_to_stack(t_stack **dest, t_stack **src);
void		swap(t_stack **stack);
//rotate.c
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
//ops_utils.c
t_ops_list	*init_ops_list(void);
t_ops		*init_ops(void);
void		add_op_to_list(t_ops **ops, char *op_name);
void		print_ops(t_ops_list *ops_list);
//benchmark.c
void    	print_bench(t_ops *ops, int bench_output,
				char *strategy, double disorder);
int 		get_bench_output(int argc, char *argv[]);
//valid operations:
//	a_ops.c
void		sa(t_stack **a, t_ops **ops);
void		pa(t_stack **a, t_stack**b, t_ops **ops);
void		ra(t_stack **a, t_ops **ops);
void		rra(t_stack **a, t_ops **ops);
//	b_ops.c
void		sb(t_stack **b, t_ops **ops);
void		pb(t_stack **a, t_stack**b, t_ops **ops);
void		rb(t_stack **b, t_ops **ops);
void		rrb(t_stack **b, t_ops **ops);
//	ab_ops.c
void		ss(t_stack **a, t_stack **b, t_ops **ops);
void		rr(t_stack **a, t_stack **b, t_ops **ops);
void		rrr(t_stack **a, t_stack **b, t_ops **ops);
//simple.c
t_ops		*simple(t_stack **a);
void		sort_b(t_stack **b, size_t b_len, t_ops **ops);
void		check_a(t_stack **a, t_stack **b, t_ops **ops);
//disorder.c
double		compute_disorder(t_stack *a);
//print_utils.c
void    	print_ops_bench(t_ops *ops, int bench_output);
void		print_bench(t_ops *ops, int bench_output,
				char *strategy, double disorder);
#endif