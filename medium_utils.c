/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium_utils.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kalnajja <kalnajja@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 18:54:24 by kalnajja         #+#    #+#              */
/*   Updated: 2026/11/21 14:29:22 by kalnajja        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_five(t_stack **a, t_ops **ops, int size)
{
	t_stack	*b;

	b = NULL;
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, ops);
		return ;
	}
	bring_to_top_a(a, 0, ops);
	pb(a, &b, ops);
	if (size != 4)
	{
		bring_to_top_a(a, 1, ops);
		pb(a, &b, ops);
	}
	sort_three_a(a, ops);
	if (size != 4)
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

void	bring_to_top_a(t_stack **a, int idx, t_ops **ops)
{
	int	pos;
	int	size;

	pos = get_pos(*a, idx);
	size = stack_size(*a);
	if (pos == -1)
		return ;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, ops);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a, ops);
	}
}
