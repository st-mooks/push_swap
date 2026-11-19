/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3way_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 22:11:01 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/19 12:11:15 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	process_element(t_stack **a, t_stack **b,
		t_ops **ops, t_segment *segment)
{
	int	group;
	int	destination;

	if (segment->location <= STACK_A_BOTTOM)
	{
		group = get_group((*a)->index, segment);
		destination = destination_of(segment->location, group);
		move_from_a(a, b, ops, destination);
	}
	else
	{
		group = get_group((*b)->index, segment);
		destination = destination_of(segment->location, group);
		move_from_b(a, b, ops, destination);
	}
}

void	set_boundaries(t_segment *segment)
{
	segment->min_boundary = segment->lowest_index
		+(segment->element_count * 42) / 100;
	segment->max_boundary = segment->lowest_index
		+(segment->element_count * 58) / 100;
}

void	set_segment(t_segment *segment, int location,
		int lowest_index, int element_count)
{
	segment->location = location;
	segment->lowest_index = lowest_index;
	segment->element_count = element_count;
}
