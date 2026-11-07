/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ab_ops.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 13:45:22 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 13:45:22 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b,
			t_ops_list **ops_list, t_ops_count **ops_count)
{
	sa(a, ops_list, ops_count);
	sb(b, ops_list, ops_count);
	add_op_to_list(ops_list, "ss");
	(*ops_count)->ss += 1;
	(*ops_count)->total += 1;
}

void	rr(t_stack **a, t_stack **b,
			t_ops_list **ops_list, t_ops_count **ops_count)
{
	rotate(a);
	rotate(b);
	add_op_to_list(ops_list, "rr");
	(*ops_count)->rr += 1;
	(*ops_count)->total += 1;
}

void	rrr(t_stack **a, t_stack **b,
			t_ops_list **ops_list, t_ops_count **ops_count)
{
	reverse_rotate(a);
	reverse_rotate(b);
	add_op_to_list(ops_list, "rrr");
	(*ops_count)->rrr += 1;
	(*ops_count)->total += 1;
}
