/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalnajja <kalnajja@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:17:11 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/09 16:35:48 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	size_t	mistakes;
	size_t	pairs;

	mistakes = 0;
	pairs = ft_lstsize((t_list *)a) - 1;
	while (a)
	{
		if (a->next && a->value > a->next->value)
			mistakes++;
		a = a->next;
	}
	return ((double)mistakes / (double)pairs);
}
