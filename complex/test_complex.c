/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_complex.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kalnajja <kalnajja@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 14:39:12 by kalnajja         #+#    #+#              */
/*   Updated: 2026/11/12 14:52:55 by kalnajja        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include <stdio.h>

static void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("[%d | %d] -> ", stack->value, stack->index);
		stack = stack->next;
	}
	printf("NULL\n");
}

static int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	free_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_ops	*ops;
	int		i;

	if (argc < 2)
		return (1);
	a = NULL;
	i = argc - 1;
	while (i >= 1)
		push(&a, atoi(argv[i--]));
	assign_index(a);
	printf("Before sorting:\n");
	print_stack(a);
	ops = complex_sort(&a);
	if (!ops)
		return (1);
	printf("\nAfter sorting:\n");
	print_stack(a);
	printf("\nResult: %s\n", is_sorted(a) ? "PASS" : "FAIL");
	printf("Operations: %d\n", ops->total);
	free_stack(a);
	free_all(NULL, ops);
	return (0);
}
