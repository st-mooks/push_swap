/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:54:24 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/16 12:04:56 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

void	bring_to_top_b(t_stack **b, int idx, t_ops **ops)
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
