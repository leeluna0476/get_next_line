/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:39:05 by seojilee          #+#    #+#             */
/*   Updated: 2025/01/29 14:45:13 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static ssize_t	read_str(int fd, char buf[])
{
	ssize_t	read_size;
	ssize_t	nul;

	read_size = read(fd, buf, BUFSIZE);
	if (read_size < 0)
		nul = 0;
	else
		nul = read_size;
	buf[nul] = '\0';
	return (read_size);
}

static ssize_t	copy_characters(char buf[], struct s_vector *vec, size_t line_gap)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (vec->size == line_gap + i + 1)
		{
			expand_vector(vec);
			if (!vec->line)
			{
				buf[0] = '\0';
				return (-1);
			}
		}
		vec->line[line_gap + i] = buf[i];
		if (buf[i++] == '\n')
		{
			vec->line[line_gap + i] = '\0';
			ft_strlcpy(buf, buf + i, BUFSIZE + 1);
			return (-1);
		}
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFSIZE + 1];
	struct s_vector	vec;
	ssize_t			copied_now;
	ssize_t			accumulated;

	vec.line = NULL;
	vec.size = 1;
	accumulated = 0;
	while (42)
	{
		if (!buf[0] && read_str(fd, buf) == -1)
			free(vec.line);
		if (!buf[0])
			break;
		copied_now= copy_characters(buf, &vec, accumulated);
		if (copied_now == -1)
			return (vec.line);
		buf[0] = '\0';
		accumulated += copied_now;
	}
	if (vec.line)
		vec.line[accumulated] = '\0';
	return (vec.line);
}
