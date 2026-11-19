/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:54:20 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/19 13:30:45 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

t_ops	*chunk_sort(t_stack **a)
{
	int		size;
	t_stack	*b;
	t_ops	*ops;

	b = NULL;
	ops = init_ops();
	assign_index(*a);
	size = stack_size(*a);
	if (size == 0)
		return (ops);
	if (size <= 3)
	{
		sort_three_a(a, &ops);
		return (ops);
	}
	chunk_push_to_b(a, &b, get_chunk_size(size), &ops);
	push_back_to_a(a, &b, &ops, size);
	return (ops);
}
