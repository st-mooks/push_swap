/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalnajja <kalnajja@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:59:39 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/07 20:59:39 by kalnajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;
	int		index;

	index = 0;
	current = stack;
	while (current)
	{
		runner = stack;
		while (runner)
		{
			if (runner->value < current->value)
				index++;
			runner = runner->next;
		}
		current->index = index;
		index = 0;
		current = current->next;
	}
}

/*
//test_assign_index
#include <stdio.h>
int	main(void)
{
t_stack	*stack;
t_stack	*current;

stack = stack_new(50);
push(&stack, -10);
push(&stack, 100);
push(&stack, 20);
assign_index(stack);
current = stack;
while (current)
{
printf("Value: %d | Index: %d\n",
current->value, current->index);
current = current->next;
}
return (0);
}
*/
