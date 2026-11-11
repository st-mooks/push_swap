/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_partition_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalnajja <kalnajja@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:38:32 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/11 15:53:29 by kalnajja         ###   ########.fr       */
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

static int	split_a(t_stack **a, t_stack **b, int size, t_ops **ops)
{
	int	pivot;
	int	pushed;
	int	i;

	i = 0;
	pushed = 0;
	pivot = get_partition_pivot(a, size);
	if (pivot == -1)
		return (0);
	while (i < size)
	{
		if ((*a)->index <= pivot)
		{
			pb(a, b, ops);
			pushed++;
		}
		else
		{
			ra(a, ops);
		}
		i++;
	}
	return (pushed);
}

int	partition_a(t_stack **a, t_stack **b, int size, t_ops **ops)
{
	int	pushed;
	int	rotated;
	int	original_size;

	original_size = stack_size(*a);
	pushed = split_a(a, b, size, ops);
	rotated = size - pushed;
	if (size != original_size)
		restore_a(a, ops, rotated);
	return (pushed);
}
