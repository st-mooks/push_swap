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

void	sa(t_stack **a)
{
	swap(a);
}

void	pa(t_stack **a, t_stack**b)
{
	push_to_stack(a, b);
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}
