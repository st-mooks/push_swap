/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 push_swap_pop.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 13:46:07 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 13:46:07 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **stack, int n)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = *stack;
	*stack = stack_new(n);
	(*stack)->next = temp;
}

void	push_to_stack(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	temp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = temp;
}

void	swap(t_stack **stack)
{
	int	temp;

	if (!stack)
		return ;
	if (*stack && (*stack)->next)
	{
		temp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = temp;
	}
}
