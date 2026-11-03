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

typedef struct s_ops_count
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
}	t_ops_count;

//valication.c
void		validate_int(int value, char *values);
void		check_duplicate(int value, t_stack *stack);
void		raise_error(void);
size_t		count_digits(int value);
int			is_option(char *str);
//list_functions.c
t_stack		*stack_new(int n);
t_stack		*stack_penultimate(t_stack *stack);
t_stack		*stack_last(t_stack *stack);
size_t		get_input_stack_len(int argc, char *argv[]);
t_stack		*stack_init(char *values[], size_t len);
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
t_ops_count	*init_ops_count(void);
void    	add_op_to_list(t_ops_list **ops_list, char *op_name);
void    	print_ops(t_ops_list *ops_list);
//valid operations:
//	a_ops.c
void		sa(t_stack **a,
            	t_ops_list **ops_list, t_ops_count **ops_count);
void		pa(t_stack **a, t_stack**b,
            	t_ops_list **ops_list, t_ops_count **ops_count);
void		ra(t_stack **a,
            	t_ops_list **ops_list, t_ops_count **ops_count);
void		rra(t_stack **a,
            	t_ops_list **ops_list, t_ops_count **ops_count);
//	b_ops.c
void		sb(t_stack **b,
            	t_ops_list **ops_list, t_ops_count **ops_count);
void		pb(t_stack **a, t_stack**b,
            	t_ops_list **ops_list, t_ops_count **ops_count);
void		rb(t_stack **b,
            	t_ops_list **ops_list, t_ops_count **ops_count);
void		rrb(t_stack **b,
            	t_ops_list **ops_list, t_ops_count **ops_count);
//	ab_ops.c
void		ss(t_stack **a, t_stack **b,
            	t_ops_list **ops_list, t_ops_count **ops_count);
void		rr(t_stack **a, t_stack **b,
            	t_ops_list **ops_list, t_ops_count **ops_count);
void		rrr(t_stack **a, t_stack **b,
            	t_ops_list **ops_list, t_ops_count **ops_count);
//simple.c
void		simple(t_stack **a, t_stack **b, size_t len);
#endif