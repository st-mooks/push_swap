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
int			validate_int(char *values);
int			check_duplicate(int value, t_stack *stack);
void		raise_error(void);
//split_input.c
int			count_args(char *args[]);
void		fill_args(char **split, char **split_arg, int original_len);
int			split_args(char **argv[]);
//list_functions.c
t_stack		*stack_new(int n);
t_stack		*stack_penultimate(t_stack *stack);
t_stack		*stack_last(t_stack *stack);
void		free_all(t_stack *a, t_ops *ops);
t_stack		*stack_init(int argc, char *argv[]);
//push_swap_pop.c
void		push(t_stack **stack, int n);
void		push_to_stack(t_stack **dest, t_stack **src);
void		swap(t_stack **stack);
//rotate.c
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
//ops_utils.c
t_ops_list	*init_ops_list(char *op_name);
t_ops		*init_ops(void);
t_ops		*get_ops(t_stack **a, int mode, double disorder);
void		add_op_to_list(t_ops **ops, char *op_name);
void		print_ops(t_ops_list *ops_list);
//input_parsing.c
size_t		get_input_stack_len(int argc, char *argv[]);
int			get_bench_output(char *argv[]);
void		check_duplicate_options(int argc, char *argv[]);
int			get_option(int argc, char *argv[]);
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
//disorder.c
double		compute_disorder(t_stack *a);
//print_utils.c
void		print_ops_bench(t_ops ops, int bench_output);
void		print_bench(t_ops ops, int bench_output,
				int mode, double disorder);
char		*get_option_str(int mode);
char		*get_strategy(int mode, double disorder);
//simple.c
t_ops		*simple(t_stack **a);
void		sort_b(t_stack **b, size_t b_len, t_ops **ops);
void		check_a(t_stack **a, t_stack **b, t_ops **ops);
#endif