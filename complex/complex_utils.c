/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalnajja <kalnajja@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:59:43 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/10 14:38:43 by kalnajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "complex.h"

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	get_pivot(int min, int max)
{
	return (min + (max - min) / 2);
}

int	min_index(t_stack *stack, int size)
{
	int	min;

	if (!stack || size <= 0)
		return (-1);
	min = stack->index;
	while (stack && size--)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	max_index(t_stack *stack, int size)
{
	int	max;

	if (!stack || size <= 0)
		return (-1);
	max = stack->index;
	while (stack && size--)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}
/*
#include <stdio.h>

int	main(void)
{
t_stack	*a;
t_stack	*b;
int		pushed;

a = NULL;
b = NULL;
push(&a, 8);
push(&a, 3);
push(&a, 6);
push(&a, 1);
push(&a, 9);
push(&a, 4);
assign_index(a);
pushed = partition_a(&a, &b, stack_size(a));
printf("Pushed: %d\n", pushed);
return (0);
}
*/
