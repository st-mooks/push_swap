/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 apply_ops.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/11 13:52:59 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/11 13:52:59 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	apply_op(char *op, t_stack **a, t_stack **b, t_ops **ops)
{
	if (!ft_strncmp(op, "sa", 2) || !ft_strncmp(op, "sa\n", 4))
		sa(a, ops);
	else if (!ft_strncmp(op, "sb", 3) || !ft_strncmp(op, "sb\n", 4))
		sb(b, ops);
	else if (!ft_strncmp(op, "ss", 3) || !ft_strncmp(op, "ss\n", 4))
		ss(a, b, ops);
	else if (!ft_strncmp(op, "pa", 3) || !ft_strncmp(op, "pa\n", 4))
		pa(a, b, ops);
	else if (!ft_strncmp(op, "pb", 3) || !ft_strncmp(op, "pb\n", 4))
		pb(a, b, ops);
	else if (!ft_strncmp(op, "ra", 3) || !ft_strncmp(op, "ra\n", 4))
		ra(a, ops);
	else if (!ft_strncmp(op, "rb", 3) || !ft_strncmp(op, "rb\n", 4))
		rb(b, ops);
	else if (!ft_strncmp(op, "rr", 3) || !ft_strncmp(op, "rr\n", 4))
		rr(a, b, ops);
	else if (!ft_strncmp(op, "rra", 4) || !ft_strncmp(op, "rra\n", 5))
		rra(a, ops);
	else if (!ft_strncmp(op, "rra", 4) || !ft_strncmp(op, "rrb\n", 5))
		rrb(b, ops);
	else if (!ft_strncmp(op, "rrb", 4) || !ft_strncmp(op, "rrr\n", 5))
		rrr(a, b, ops);
}

void	check_op(char *op)
{
	if (!op
		|| !ft_strncmp(op, "sa", 3) || !ft_strncmp(op, "sa\n", 4)
		|| !ft_strncmp(op, "sb", 3) || !ft_strncmp(op, "sb\n", 4)
		|| !ft_strncmp(op, "ss", 3) || !ft_strncmp(op, "ss\n", 4)
		|| !ft_strncmp(op, "ra", 3) || !ft_strncmp(op, "ra\n", 4)
		|| !ft_strncmp(op, "rb", 3) || !ft_strncmp(op, "rb\n", 4)
		|| !ft_strncmp(op, "rr", 3) || !ft_strncmp(op, "rr\n", 4)
		|| !ft_strncmp(op, "pa", 3) || !ft_strncmp(op, "pa\n", 4)
		|| !ft_strncmp(op, "pb", 3) || !ft_strncmp(op, "pb\n", 4)
		|| !ft_strncmp(op, "sb", 3) || !ft_strncmp(op, "sb\n", 4)
		|| !ft_strncmp(op, "rra", 4) || !ft_strncmp(op, "rra\n", 5)
		|| !ft_strncmp(op, "rrb", 4) || !ft_strncmp(op, "rrb\n", 5)
		|| !ft_strncmp(op, "rrr", 4) || !ft_strncmp(op, "rrr\n", 5)
	)
		return ;
	raise_error();
}
