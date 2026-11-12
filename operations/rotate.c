/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 rotate.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 13:46:27 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 13:46:27 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (!stack || !*stack)
		return ;
	last = stack_last(*stack);
	penultimate = stack_penultimate(*stack);
	last->next = *stack;
	*stack = last;
	penultimate->next = NULL;
}

void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack)
		return ;
	last = *stack;
	*stack = (*stack)->next;
	stack_last(*stack)->next = last;
	last->next = NULL;
}
