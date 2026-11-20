/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3way_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:07:35 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/19 12:11:18 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	destination_of(int location, int group)
{
	if (group == GROUP_MAX)
	{
		if (location == STACK_A_TOP)
			return (STACK_A_BOTTOM);
		return (STACK_A_TOP);
	}
	if (group == GROUP_MIDDLE)
	{
		if (location <= STACK_A_BOTTOM)
			return (STACK_B_BOTTOM);
		return (STACK_A_BOTTOM);
	}
	if (location == STACK_B_TOP)
		return (STACK_B_BOTTOM);
	return (STACK_B_TOP);
}

int	get_group(int index, t_segment *segment)
{
	if (index < segment->min_boundary)
		return (GROUP_MIN);
	if (index < segment->max_boundary)
		return (GROUP_MIDDLE);
	return (GROUP_MAX);
}

void	fetch_segment(t_stack **a, t_stack **b, t_ops **ops, int location)
{
	if (location == STACK_A_BOTTOM)
		rra(a, ops);
	else if (location == STACK_B_BOTTOM)
		rrb(b, ops);
}

void	move_from_a(t_stack **a, t_stack **b, t_ops **ops, int destination)
{
	if (destination == STACK_A_BOTTOM)
		ra(a, ops);
	else if (destination == STACK_B_TOP)
		pb(a, b, ops);
	else if (destination == STACK_B_BOTTOM)
	{
		pb(a, b, ops);
		rb(b, ops);
	}
}

void	move_from_b(t_stack **a, t_stack **b, t_ops **ops, int destination)
{
	if (destination == STACK_B_BOTTOM)
		rb(b, ops);
	else if (destination == STACK_A_TOP)
		pa(a, b, ops);
	else if (destination == STACK_A_BOTTOM)
	{
		pa(a, b, ops);
		ra(a, ops);
	}
}
