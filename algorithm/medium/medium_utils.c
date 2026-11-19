/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:54:24 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/19 13:59:50 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_five(t_stack **a, t_ops **ops)
{
	t_stack	*b;

	b = NULL;
	bring_to_top(a, 0, ops);
	pb(a, &b, ops);
	bring_to_top(a, 1, ops);
	pb(a, &b, ops);
	sort_three_a(a, ops);
	pa(a, &b, ops);
	pa(a, &b, ops);
}

int	get_pos(t_stack *stack, int idx)
{
	t_stack	*cur;
	int		pos;

	cur = stack;
	pos = 0;
	while (cur)
	{
		if (cur->index == idx)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

void	bring_to_top(t_stack **b, int idx, t_ops **ops)
{
	int	pos;
	int	size;

	pos = get_pos(*b, idx);
	size = stack_size(*b);
	if (pos == -1)
		return ;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b, ops);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rrb(b, ops);
			pos--;
		}
	}
}
