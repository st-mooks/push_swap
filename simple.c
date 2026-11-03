/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:20:40 by mbadarin          #+#    #+#             */
/*   Updated: 2026/11/03 18:22:05 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_a(t_stack **a, t_stack **b)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
	pb(a, b);
}

void	sort_b(t_stack **b, size_t b_len)
{
	int	rotations;

	rotations = 0;
	while (b_len > 0 && (*b)->value < (*b)->next->value)
	{
		sb(b);
		rrb(b);
		b_len--;
		rotations++;
	}
	while (rotations > 0)
	{
		rb(b);
		rotations--;
	}
}

void	simple(t_stack **a, t_stack **b, size_t len)
{
	int	i;
	int	b_len;

	i = 0;
	while (i + 1 < len)
	{
		check_a(a, b);
		i++;
		b_len = i - 1;
		sort_b(b, b_len);
	}
	while (i-- > 0)
		pa(a, b);
}
