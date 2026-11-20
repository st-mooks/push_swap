/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3way_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:38:03 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/19 13:27:37 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	solve_children(t_stack **a, t_stack **b,
		t_ops **ops, t_segment *segment)
{
	t_segment	child;
	int			size;

	size = segment->lowest_index + segment->element_count
		-segment->max_boundary;
	set_segment(&child, destination_of(segment->location, GROUP_MAX),
		segment->max_boundary, size);
	solve_segments(a, b, ops, &child);
	size = segment->max_boundary - segment->min_boundary;
	set_segment(&child,
		destination_of(segment->location, GROUP_MIDDLE),
		segment->min_boundary, size);
	solve_segments(a, b, ops, &child);
	size = segment->min_boundary - segment->lowest_index;
	set_segment(&child,
		destination_of(segment->location, GROUP_MIN),
		segment->lowest_index, size);
	solve_segments(a, b, ops, &child);
}

void	solve_segments(t_stack **a, t_stack **b,
		t_ops **ops, t_segment *segment)
{
	int	i;

	if (segment->element_count <= 0)
		return ;
	if (segment->element_count <= 2)
	{
		base_sort(a, b, ops, segment);
		return ;
	}
	set_boundaries(segment);
	i = 0;
	while (i < segment->element_count)
	{
		fetch_segment(a, b, ops, segment->location);
		process_element(a, b, ops, segment);
		i++;
	}
	solve_children(a, b, ops, segment);
}

t_ops	*three_way_sort(t_stack **a)
{
	t_ops		*ops;
	t_stack		*b;
	t_segment	segment;
	int			size;

	ops = init_ops();
	b = NULL;
	assign_index(*a);
	size = stack_size(*a);
	if (size == 3)
	{
		sort_three_a(a, &ops);
		return (ops);
	}
	set_segment(&segment, STACK_A_TOP, 0, size);
	solve_segments(a, &b, &ops, &segment);
	return (ops);
}
