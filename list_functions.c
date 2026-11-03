/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 list_functions.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 13:45:43 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 13:45:43 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = n;
	new->next = NULL;
	return (new);
}

t_stack	*stack_penultimate(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_init(int len, char *values[])
{
	int		value;
	t_stack	*stack;

	value = ft_atoi(values[--len]);
	validate_int(value, values[len--]);
	stack = stack_new(value);
	if (!stack)
		return (NULL);
	while (len > 0)
	{
		if (is_option(values[len]))
		{
			len--;
			continue ;
		}
		value = ft_atoi(values[len]);
		validate_int(value, values[len--]);
		check_duplicate(value, stack);
		push(&stack, value);
	}
	return (stack);
}
