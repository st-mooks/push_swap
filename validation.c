/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 validation.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/03 13:46:34 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/11/03 13:46:34 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "./push_swap.h"

void	raise_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

size_t	digit_count(int i)
{
	size_t	count;

	count = 0;
	if (i <= 0)
		count++;
	while (i != 0)
	{
		count++;
		i /= 10;
	}
	return (count);
}

int	validate_int(char *value_str)
{
	int	i;

	i = ft_atoi(value_str);
	if (ft_strlen(value_str) != digit_count(i))
		return (0);
	if (*value_str == '+' || *value_str == '-')
		value_str += 1;
	while (*value_str && ft_isdigit(*value_str))
		value_str += 1;
	if (*value_str)
		return (0);
	return (1);
}

int	check_duplicate(int value, t_stack *stack)
{
	while (stack)
	{
		if (stack->value == value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
