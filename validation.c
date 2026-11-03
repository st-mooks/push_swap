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

#include "push_swap.h"

void	raise_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

size_t	count_digits(int value)
{
	size_t	count;

	if (value == INT_MIN)
		return (10);
	if (value == 0)
		return (1);
	if (value < 0)
		value *= -1;
	count = 0;
	while (value != 0)
	{
		count += 1;
		value /= 10;
	}
	return (count);
}

void	validate_int(int value, char *value_str)
{
	if (value == 0 && *value_str != '0')
		raise_error();
	if (count_digits(value) != ft_strlen(value_str))
		raise_error();
}

void	check_duplicate(int value, t_stack *stack)
{
	while (stack)
	{
		if (stack->value == value)
			raise_error();
		stack = stack->next;
	}
}

int	is_option(char *str)
{
	if (!ft_strncmp(str, "--simple", ft_strlen("--simple") + 1)
		|| !ft_strncmp(str, "--medium", ft_strlen("--medium") + 1)
		|| !ft_strncmp(str, "--complex", ft_strlen("--complex") + 1)
		|| !ft_strncmp(str, "--adaptive", ft_strlen("--adaptive") + 1)
		|| !ft_strncmp(str, "--bench", ft_strlen("--bench") + 1))
		return (1);
	return (0);
}
