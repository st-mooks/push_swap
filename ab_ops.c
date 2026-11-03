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

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
