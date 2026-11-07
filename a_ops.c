/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 a_ops.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 13:45:05 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 13:45:05 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_ops_list **ops_list, t_ops_count **ops_count)
{
	swap(a);
	add_op_to_list(ops_list, "sa");
	(*ops_count)->sa += 1;
	(*ops_count)->total += 1;
}

void	pa(t_stack **a, t_stack**b,
			t_ops_list **ops_list, t_ops_count **ops_count)
{
	push_to_stack(a, b);
	add_op_to_list(ops_list, "pa");
	(*ops_count)->pa += 1;
	(*ops_count)->total += 1;
}

void	ra(t_stack **a, t_ops_list **ops_list, t_ops_count **ops_count)
{
	rotate(a);
	add_op_to_list(ops_list, "ra");
	(*ops_count)->ra += 1;
	(*ops_count)->total += 1;
}

void	rra(t_stack **a, t_ops_list **ops_list, t_ops_count **ops_count)
{
	reverse_rotate(a);
	add_op_to_list(ops_list, "rra");
	(*ops_count)->rra += 1;
	(*ops_count)->total += 1;
}
