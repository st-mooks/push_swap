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

#include "../push_swap.h"

void	sa(t_stack **a, t_ops **ops)
{
	swap(a);
	add_op_to_list(ops, "sa");
	(*ops)->sa_count += 1;
	(*ops)->total += 1;
}

void	pa(t_stack **a, t_stack**b, t_ops **ops)
{
	push_to_stack(a, b);
	add_op_to_list(ops, "pa");
	(*ops)->pa_count += 1;
	(*ops)->total += 1;
}

void	ra(t_stack **a, t_ops **ops)
{
	rotate(a);
	add_op_to_list(ops, "ra");
	(*ops)->ra_count += 1;
	(*ops)->total += 1;
}

void	rra(t_stack **a, t_ops **ops)
{
	reverse_rotate(a);
	add_op_to_list(ops, "rra");
	(*ops)->rra_count += 1;
	(*ops)->total += 1;
}
