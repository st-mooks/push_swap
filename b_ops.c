/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 b_ops.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 13:45:31 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 13:45:31 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b, t_ops **ops)
{
	swap(b);
	add_op_to_list(ops, "sb");
	(*ops)->sb_count += 1;
	(*ops)->total += 1;
}

void	pb(t_stack **a, t_stack**b, t_ops **ops)
{
	push_to_stack(b, a);
	add_op_to_list(ops, "pb");
	(*ops)->pb_count += 1;
	(*ops)->total += 1;
}

void	rb(t_stack **b, t_ops **ops)
{
	rotate(b);
	add_op_to_list(ops, "rb");
	(*ops)->rb_count += 1;
	(*ops)->total += 1;
}

void	rrb(t_stack **b, t_ops **ops)
{
	reverse_rotate(b);
	add_op_to_list(ops, "rrb");
	(*ops)->rrb_count += 1;
	(*ops)->total += 1;
}
