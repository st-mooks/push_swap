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

//valication.c
void	validate_int(int value, char *values);
void	check_duplicate(int value, t_stack *stack);
void	raise_error(void);
size_t	count_digits(int value);
int		is_option(char *str);
//list_functions.c
t_stack	*stack_new(int n);
t_stack	*stack_penultimate(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_init(int len, char *values[]);
//push_swap_pop.c
void	push(t_stack **stack, int n);
void	pop(t_stack **stack);
void	push_to_stack(t_stack **dest, t_stack **src);
void	swap(t_stack **stack);
//rotate.c
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
//valid operations:
//	a_ops.c
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack**b);
void	ra(t_stack **a);
void	rra(t_stack **a);
//	b_ops.c
void	sb(t_stack **b);
void	pb(t_stack **a, t_stack**b);
void	rb(t_stack **b);
void	rrb(t_stack **b);
//	ab_ops.c
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
#endif