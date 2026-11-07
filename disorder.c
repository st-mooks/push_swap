/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalnajja <kalnajja@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:17:11 by kalnajja          #+#    #+#             */
/*   Updated: 2026/11/04 17:44:29 by kalnajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_percentage(int integer_part, int decimal_part)
{
	char	*str;

	str = ft_itoa(integer_part);
	write(1, "Disorder: ", 10);
	write(1, str, ft_strlen(str));
	write(1, ".", 1);
	free(str);
	if (decimal_part < 10)
		write(1, "0", 1);
	str = ft_itoa(decimal_part);
	write(1, str, ft_strlen(str));
	free(str);
	write(1, "%\n", 2);
}

static int	ft_round_percentage(double percentage)
{
	return ((int)(percentage * 100 + 0.5));
}

void	print_disorder(size_t mistakes, size_t total)
{
	int		rounded;
	double	percentage;

	if (total == 0)
	{
		write(1, "Disorder: 0.00%\n", 16);
		return ;
	}
	percentage = ((double) mistakes / total) * 100;
	rounded = ft_round_percentage(percentage);
	print_percentage(rounded / 100, rounded % 100);
}

void	compute_disorder(t_stack *a, size_t *mistakes, size_t *total)
{
	t_stack	*i;
	t_stack	*j;

	*total = 0;
	*mistakes = 0;
	i = a;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			(*total)++;
			if (i->value > j->value)
				(*mistakes)++;
			j = j->next;
		}
		i = i->next;
	}
}
/*
int	main(void)
{
t_stack	*a;
size_t	total;
size_t	mistakes;

a = NULL;
push(&a, 3);
push(&a, 2);
push(&a, 1);
compute_disorder(a, &mistakes, &total);
print_disorder(mistakes, total);
return (0);
}
*/
