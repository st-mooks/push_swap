/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalnajja <kalnajja@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:59:43 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/10 11:01:57 by kalnajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	partition_a(t_stack **a, t_stack **b, int size, t_ops *ops)
{
	int	pivot;
	int	pushed;
	int	i; 

	i = 0;
	pushed = 0;
	if (!a || !*a || size <= 0)
		return (0);
	if (size > stack_size(*a))
		return (0);
	pivot = get_pivot(min_index(*a, size), max_index(*a, size));
	while (i < size)
	{
		if ((*a)->index <= pivot)
		{
			pb(a, b, &ops->list, &ops->count);
			pushed++;
		}
		else
			ra(a, &ops->list, &ops->count);
		i++;
	}
	return (pushed);
}

int	min_index(t_stack *stack,int size)
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

int	max_index(t_stack *stack,int size)
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
