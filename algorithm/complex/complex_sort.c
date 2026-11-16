/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 23:40:06 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/16 11:52:40 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	quick_sort_a(t_stack **a, t_stack **b, int size, t_ops **ops)
{
	int	pushed;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, ops);
		return ;
	}
	pushed = partition_a(a, b, size, ops);
	quick_sort_a(a, b, size - pushed, ops);
	quick_sort_b(a, b, pushed, ops);
}

void	quick_sort_b(t_stack **a, t_stack **b, int size, t_ops **ops)
{
	int	pushed;

	if (size <= 0)
		return ;
	if (size == 1)
	{
		pa(a, b, ops);
		return ;
	}
	if (size == 2)
	{
		if ((*b)->index < (*b)->next->index)
			sb(b, ops);
		pa(a, b, ops);
		pa(a, b, ops);
		return ;
	}
	pushed = partition_b(a, b, size, ops);
	quick_sort_a(a, b, pushed, ops);
	quick_sort_b(a, b, size - pushed, ops);
}

t_ops	*complex_sort(t_stack **a)
{
	t_stack	*b;
	t_ops	*ops;

	b = NULL;
	ops = init_ops();
	if (!ops)
		return (NULL);
	quick_sort_a(a, &b, stack_size(*a), &ops);
	return (ops);
}
