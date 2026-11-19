/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:54:25 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/19 13:59:48 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push_small_to_b(t_stack **a, t_stack **b,
	t_chunk *data, t_ops **ops)
{
	pb(a, b, ops);
	if ((*b)->next)
		rb(b, ops);
	data->pushed++;
}

static void	push_to_b(t_stack **a, t_stack **b, t_chunk *data, t_ops **ops)
{
	pb(a, b, ops);
	data->pushed++;
}

static void	push_one_to_b(t_stack **a, t_stack **b, t_chunk *data, t_ops **ops)
{
	int	rotations;
	int	size;

	size = stack_size(*a);
	rotations = 0;
	while (rotations < size && *a)
	{
		if ((*a)->index <= data->pushed)
		{
			push_small_to_b(a, b, data, ops);
			break ;
		}
		else if ((*a)->index <= data->pushed + data->chunk)
		{
			push_to_b(a, b, data, ops);
			break ;
		}
		else
		{
			ra(a, ops);
			rotations++;
		}
	}
}

void	chunk_push_to_b(t_stack **a, t_stack **b, int chunk, t_ops **ops)
{
	t_chunk	data;

	data.pushed = 0;
	data.chunk = chunk;
	while (*a)
		push_one_to_b(a, b, &data, ops);
}

void	push_back_to_a(t_stack **a, t_stack **b, t_ops **ops, int size)
{
	int	max;

	max = size - 1;
	while (*b)
	{
		bring_to_top(b, max, ops);
		pa(a, b, ops);
		max--;
	}
}
