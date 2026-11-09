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

char	*get_option(int argc, char *argv[])
{
	int		count;
	char	*option;
	char	*str;

	count = 0;
	option = NULL;
	while (--argc > 0)
	{
		str = argv[argc];
		if (!ft_strncmp(str, "--simple", ft_strlen("--simple") + 1)
			|| !ft_strncmp(str, "--medium", ft_strlen("--medium") + 1)
			|| !ft_strncmp(str, "--complex", ft_strlen("--complex") + 1)
			|| !ft_strncmp(str, "--adaptive", ft_strlen("--adaptive") + 1))
		{
			option = str;
			count++;
		}
	}
	if (count > 1)
		raise_error();
	return (option);
}
