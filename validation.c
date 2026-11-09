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

void	validate_int(int value, char *value_str)
{
	if (*value_str == '+' || *value_str == '-')
		value_str += 1;
	while (*value_str && ft_isdigit(*value_str))
		value_str += 1;
	if (*value_str)
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

int	get_option(int argc, char *argv[])
{
	int		count;
	int		option;
	char	*str;

	count = 0;
	option = 0;
	while (--argc > 0)
	{
		str = argv[argc];
		if (!ft_strncmp(str, "--simple", ft_strlen("--simple") + 1))
		{
			option = 1;
			count++;
		}
		if (!ft_strncmp(str, "--medium", ft_strlen("--medium") + 1))
		{
			option = 2;
			count++;
		}
		if (!ft_strncmp(str, "--complex", ft_strlen("--complex") + 1))
		{
			option = 3;
			count++;
		}
	}
	if (count > 1)
		raise_error();
	return (option);
}
