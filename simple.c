/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 simple.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 18:20:40 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 18:22:05 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"

void	check_a(t_stack **a, t_stack **b,
			t_ops_list **ops_list, t_ops_count **ops_count)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, ops_list, ops_count);
	pb(a, b, ops_list, ops_count);
}

void	sort_b(t_stack **b, size_t b_len,
			t_ops_list **ops_list, t_ops_count **ops_count)
{
	int	rotations;

	rotations = 0;
	while (b_len > 0 && (*b)->value < (*b)->next->value)
	{
		sb(b, ops_list, ops_count);
		rrb(b, ops_list, ops_count);
		b_len--;
		rotations++;
	}
	while (rotations > 0)
	{
		rb(b, ops_list, ops_count);
		rotations--;
	}
}

void	simple(t_stack **a, t_stack **b, size_t len)
{
	int			i;
	int			b_len;
	t_ops_list	*ops_list;
	t_ops_count	*ops_count;

	ops_list = init_ops_list();
	ops_count = init_ops_count();
	i = 0;
	while (i + 1 < len)
	{
		check_a(a, b, &ops_list, &ops_count);
		i++;
		b_len = i - 1;
		sort_b(b, b_len, &ops_list, &ops_count);
	}
	while (i-- > 0)
		pa(a, b, &ops_list, &ops_count);
	print_ops(ops_list);
}
