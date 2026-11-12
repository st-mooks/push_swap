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

#include "../push_swap.h"

void	check_a(t_stack **a, t_stack **b, t_ops **ops)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, ops);
	pb(a, b, ops);
}

void	sort_b(t_stack **b, size_t b_len, t_ops **ops)
{
	int	rotations;

	rotations = 0;
	while (b_len > 0 && (*b)->value < (*b)->next->value)
	{
		sb(b, ops);
		rb(b, ops);
		b_len--;
		rotations++;
	}
	while (rotations > 0)
	{
		rrb(b, ops);
		rotations--;
	}
}

t_ops	*simple(t_stack **a)
{
	int		i;
	int		b_len;
	int		len;
	t_stack	*b;
	t_ops	*ops;

	len = (int)ft_lstsize((t_list *)*a);
	ops = init_ops();
	b = NULL;
	i = 0;
	while (i + 1 < len)
	{
		check_a(a, &b, &ops);
		i++;
		b_len = i - 1;
		sort_b(&b, b_len, &ops);
	}
	while (i-- > 0)
		pa(a, &b, &ops);
	return (ops);
}
