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

#include "../push_swap.h"

void	raise_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	validate_int(char *value_str)
{
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
