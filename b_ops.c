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

void	sb(t_stack **b)
{
	swap(b);
}

void	pb(t_stack **a, t_stack**b)
{
	push_to_stack(b, a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}
