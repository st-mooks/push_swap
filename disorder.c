/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:17:11 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/23 10:16:14 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	get_mistakes(int j, size_t size, t_stack *a, t_stack *temp)
{
	int	mistakes;

	mistakes = 0;
	while (j < size)
	{
		if (temp->next && a->value > temp->next->value)
			mistakes++;
		j++;
		temp = temp->next;
	}
	return (mistakes);
}

double	compute_disorder(t_stack *a)
{
	t_stack	*temp;
	size_t	mistakes;
	size_t	size;
	size_t	i;
	size_t	j;

	mistakes = 0;
	size = ft_lstsize((t_list *)a);
	i = 0;
	while (i + 1 < size)
	{
		j = i + 1;
		temp = a;
		mistakes += get_mistakes(j, size, a, temp);
		i++;
		a = a->next;
	}
	if (size <= 1)
		return (0);
	return ((double)mistakes / (size * (size - 1) / 2));
}
