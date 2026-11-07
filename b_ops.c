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

void	sb(t_stack **b, t_ops_list **ops_list, t_ops_count **ops_count)
{
	swap(b);
	add_op_to_list(ops_list, "sb");
	(*ops_count)->sb += 1;
	(*ops_count)->total += 1;
}

void	pb(t_stack **a, t_stack**b,
			t_ops_list **ops_list, t_ops_count **ops_count)
{
	push_to_stack(b, a);
	add_op_to_list(ops_list, "pb");
	(*ops_count)->pb += 1;
	(*ops_count)->total += 1;
}

void	rb(t_stack **b, t_ops_list **ops_list, t_ops_count **ops_count)
{
	rotate(b);
	add_op_to_list(ops_list, "rb");
	(*ops_count)->rb += 1;
	(*ops_count)->total += 1;
}

void	rrb(t_stack **b, t_ops_list **ops_list, t_ops_count **ops_count)
{
	reverse_rotate(b);
	add_op_to_list(ops_list, "rrb");
	(*ops_count)->rrb += 1;
	(*ops_count)->total += 1;
}
