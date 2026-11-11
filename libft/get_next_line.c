/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:15:53 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/23 12:21:06 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_char(char *str, char c)
{
	char	*new;
	size_t	len;

	if (!str)
	{
		new = malloc(2);
		if (!new)
			return (NULL);
		new[0] = c;
		new[1] = '\0';
	}
	else
	{
		len = ft_strlen(str);
		new = malloc(len + 2);
		if (!new)
			return (NULL);
		ft_memmove(new, str, len);
		new[len] = c;
		new[len + 1] = '\0';
	}
	free(str);
	return (new);
}

void	parse_buffer(char **line, char *buf, int fd)
{
	int		i;
	ssize_t	len;

	i = 0;
	len = (ssize_t)ft_strlen(buf);
	while (buf[i] && buf[i] != '\n')
		*line = add_char(*line, buf[i++]);
	if (buf[i] == '\n')
	{
		*line = add_char(*line, buf[i++]);
		ft_memmove(buf, buf + i, len - i + 1);
		return ;
	}
	len = read(fd, buf, BUFFER_SIZE);
	if (len <= 0)
	{
		*buf = '\0';
		return ;
	}
	buf[len] = '\0';
	parse_buffer(line, buf, fd);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		buf[BUFFER_SIZE + 1] = "";

	line = NULL;
	parse_buffer(&line, buf, fd);
	return (line);
}
