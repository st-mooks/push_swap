/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   complex_partition_b.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kalnajja <kalnajja@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/11 15:53:38 by kalnajja         #+#    #+#              */
/*   Updated: 2026/11/11 17:25:36 by kalnajja        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "complex.h"

static void	restore_b(t_stack **b, t_ops **ops, int rotated)
{
	while (rotated > 0)
	{
		rrb(b, ops);
		rotated--;
	}
}

static int	get_partition_pivot_b(t_stack **b, int size)
{
	if (!b || !*b || size <= 0 || size > stack_size(*b))
		return (-1);
	return (get_pivot(min_index(*b, size), max_index(*b, size)));
}

static int	split_b(t_stack **a, t_stack **b, int size, t_ops **ops)
{
	int	pivot;
	int	pushed;
	int	i;

	i = 0;
	pushed = 0;
	pivot = get_partition_pivot_b(b, size);
	if (pivot == -1)
		return (0);
	while (i < size)
	{
		if ((*b)->index > pivot)
		{
			pa(a, b, ops);
			pushed++;
		}
		else
			rb(b, ops);
		i++;
	}
	return (pushed);
}

int	partition_b(t_stack **a, t_stack **b, int size, t_ops **ops)
{
	int	pushed;
	int	rotated;
	int	original_size;

	original_size = stack_size(*b);
	pushed = split_b(a, b, size, ops);
	rotated = size - pushed;
	if (size != original_size)
		restore_b(b, ops, rotated);
	return (pushed);
}
