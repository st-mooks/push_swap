/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:59:39 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/16 11:52:58 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
