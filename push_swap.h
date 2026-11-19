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

# ifndef STACK_A_TOP
#  define STACK_A_TOP 0
# endif

# ifndef STACK_A_BOTTOM
#  define STACK_A_BOTTOM 1
# endif

# ifndef STACK_B_TOP
#  define STACK_B_TOP 2
# endif

# ifndef STACK_B_BOTTOM
#  define STACK_B_BOTTOM 3
# endif

# ifndef GROUP_MAX
#  define GROUP_MAX 0
# endif

# ifndef GROUP_MIDDLE
#  define GROUP_MIDDLE 1
# endif

# ifndef GROUP_MIN
#  define GROUP_MIN 2
# endif

typedef struct s_stack
{
	int				value;
	int				index;
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

typedef struct s_segment
{
	int	location;
	int	lowest_index;
	int	element_count;
	int	min_boundary;
	int	max_boundary;
}	t_segment;

typedef struct s_chunk
{
	int	pushed;
	int	chunk;
}	t_chunk;

//valication.c
int			validate_int(char *values);
int			check_duplicate(int value, t_stack *stack);
void		raise_error(void);
//split_input.c
int			count_args(char *args[]);
void		fill_str(char **str, char *argv[]);
size_t		get_args_len(char *argv[]);
int			split_args(char **argv[]);
void		free_arr(char **arr);
//list_functions.c
t_stack		*stack_new(int n);
t_stack		*stack_penultimate(t_stack *stack);
t_stack		*stack_last(t_stack *stack);
void		free_all(t_stack *a, t_ops *ops);
t_stack		*stack_init(int argc, char *argv[], int mode, int bench_output);
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
int			get_input_stack_len(int argc, int mode, int bench_output);
int			get_bench_output(char *argv[]);
void		check_duplicate_options(int argc, char *argv[]);
int			get_option(int argc, char *argv[]);
//valid operations:
//	a_ops.c
void		sa(t_stack **a, t_ops **ops);
void		pa(t_stack **a, t_stack **b, t_ops **ops);
void		ra(t_stack **a, t_ops **ops);
void		rra(t_stack **a, t_ops **ops);
//	b_ops.c
void		sb(t_stack **b, t_ops **ops);
void		pb(t_stack **a, t_stack **b, t_ops **ops);
void		rb(t_stack **b, t_ops **ops);
void		rrb(t_stack **b, t_ops **ops);
//	ab_ops.c
void		ss(t_stack **a, t_stack **b, t_ops **ops);
void		rr(t_stack **a, t_stack **b, t_ops **ops);
void		rrr(t_stack **a, t_stack **b, t_ops **ops);
//disorder.c
double		compute_disorder(t_stack *a);
//print_utils.c
void		print_ops_bench(t_ops ops);
void		print_bench(t_ops ops, int mode, double disorder);
char		*get_option_str(int mode);
char		*get_strategy(int mode, double disorder);
//simple.c
t_ops		*simple(t_stack **a);
void		sort_b(t_stack **b, size_t b_len, t_ops **ops);
void		push_b(t_stack **a, t_stack **b, t_ops **ops);
//complex
int			destination_of(int location, int group);
int			get_group(int index, t_segment *segment);
void		fetch_segment(t_stack **a, t_stack **b, t_ops **ops, int location);
void		move_from_a(t_stack **a, t_stack **b, t_ops **ops, int destination);
void		move_from_b(t_stack **a, t_stack **b, t_ops **ops, int destination);
void		sort_three_a(t_stack **a, t_ops **ops);
void		sort_three_b(t_stack **b, t_ops **ops);
void		base_sort(t_stack **a, t_stack **b, t_ops **ops,
				t_segment *segment);
void		process_element(t_stack **a, t_stack **b,
				t_ops	**ops, t_segment *segment);
void		set_boundaries(t_segment *segment);
void		solve_segments(t_stack **a, t_stack **b,
				t_ops **ops, t_segment *segment);
void		set_segment(t_segment *segment, int location,
				int lowest_index, int element_count);
t_ops		*three_way_sort(t_stack **a);
//medium
int			get_pos(t_stack *s, int idx);
void		bring_to_top(t_stack **b, int idx, t_ops **ops);
int			get_chunk_size(int size);
void		chunk_push_to_b(t_stack **a, t_stack **b, int chunk, t_ops **ops);
void		push_back_to_a(t_stack **a, t_stack **b, t_ops **ops, int size);
t_ops		*chunk_sort(t_stack **a);
void		sort_five(t_stack **a, t_ops **ops, int size);
//utils_medium_complex.c
void		assign_index(t_stack *stack);
int			stack_size(t_stack *stack);
#endif