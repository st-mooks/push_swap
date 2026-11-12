/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_partition_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalnajja <kalnajja@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:38:32 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/12 16:09:26 by kalnajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "complex.h"

static void	restore_a(t_stack **a, t_ops **ops, int rotated)
{
	while (rotated > 0)
	{
		rra(a, ops);
		rotated--;
	}
}

static int	get_partition_pivot(t_stack **a, int size)
{
	if (!a || !*a || size <= 0 || size > stack_size(*a))
		return (-1);
	return (get_pivot(min_index(*a, size), max_index(*a, size)));
}

static int	process_a(t_stack **a, t_stack **b, t_ops **ops, int pivot)
{
	if ((*a)->index <= pivot)
	{
		pb(a, b, ops);
		return (1);
	}
	ra(a, ops);
	return (0);
}

static int	split_a(t_stack **a, t_stack **b, t_ops **ops, t_partition *part)
{
	int	pivot;
	int	pushed;
	int	target;
	int	i;

	i = 0;
	pushed = 0;
	part->rotated = 0;
	pivot = get_partition_pivot(a, part->size);
	if (pivot == -1)
		return (0);
	target = pivot - min_index(*a, part->size) + 1;
	while (i < part->size && pushed < target)
	{
		if (process_a(a, b, ops, pivot))
			pushed++;
		else
			part->rotated++;
		i++;
	}
	return (pushed);
}

int	partition_a(t_stack **a, t_stack **b, int size, t_ops **ops)
{
	int			pushed;
	int			original_size;
	t_partition	part;

	original_size = stack_size(*a);
	part.size = size;
	pushed = split_a(a, b, ops, &part);
	if (size != original_size)
		restore_a(a, ops, part.rotated);
	return (pushed);
}
