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

void	ss(t_stack **a, t_stack **b, t_ops **ops)
{
	sa(a, ops);
	sb(b, ops);
	add_op_to_list(ops, "ss");
	(*ops)->ss_count += 1;
	(*ops)->total += 1;
}

void	rr(t_stack **a, t_stack **b, t_ops **ops)
{
	rotate(a);
	rotate(b);
	add_op_to_list(ops, "rr");
	(*ops)->rr_count += 1;
	(*ops)->total += 1;
}

void	rrr(t_stack **a, t_stack **b, t_ops **ops)
{
	reverse_rotate(a);
	reverse_rotate(b);
	add_op_to_list(ops, "rrr");
	(*ops)->rrr_count += 1;
	(*ops)->total += 1;
}
