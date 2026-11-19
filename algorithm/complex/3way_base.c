/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3way_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:56:03 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/19 12:11:11 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three_a(t_stack **a, t_ops **ops)
{
	if ((*a)->index > (*a)->next->index)
	{
		if ((*a)->next->index > (*a)->next->next->index)
		{
			sa(a, ops);
			rra(a, ops);
		}
		else if ((*a)->index > (*a)->next->next->index)
			ra(a, ops);
		else
			sa(a, ops);
	}
	else if ((*a)->next->index > (*a)->next->next->index)
	{
		if ((*a)->index > (*a)->next->next->index)
			rra(a, ops);
		else
		{
			rra(a, ops);
			sa(a, ops);
		}
	}
}

void	sort_three_b(t_stack **b, t_ops **ops)
{
	if ((*b)->index < (*b)->next->index)
	{
		if ((*b)->next->index < (*b)->next->next->index)
		{
			sb(b, ops);
			rrb(b, ops);
		}
		else if ((*b)->index < (*b)->next->next->index)
			rb(b, ops);
		else
			sb(b, ops);
	}
	else
	{
		if ((*b)->next->index < (*b)->next->next->index)
		{
			if ((*b)->index > (*b)->next->next->index)
			{
				rrb(b, ops);
				sb(b, ops);
			}
			else
				rrb(b, ops);
		}
	}
}

static void	base_a(t_stack **a, t_ops **ops, int size)
{
	if (size == 2 && (*a)->index > (*a)->next->index)
		sa(a, ops);
	else if (size == 3)
		sort_three_a(a, ops);
}

static void	base_b(t_stack **a, t_stack **b, t_ops **ops, int size)
{
	int	i;

	if (size == 2 && (*b)->index < (*b)->next->index)
		sb(b, ops);
	else if (size == 3)
		sort_three_b(b, ops);
	i = 0;
	while (i < size)
	{
		pa(a, b, ops);
		i++;
	}
}

void	base_sort(t_stack **a, t_stack **b, t_ops **ops, t_segment *segment)
{
	int	i;

	i = 0;
	while (i < segment->element_count)
	{
		fetch_segment(a, b, ops, segment->location);
		i++;
	}
	if (segment->location <= STACK_A_BOTTOM)
		base_a(a, ops, segment->element_count);
	else
		base_b(a, b, ops, segment->element_count);
}
