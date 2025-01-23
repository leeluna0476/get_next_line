/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:39:05 by seojilee          #+#    #+#             */
/*   Updated: 2025/01/23 11:46:36 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
copy 조건:
old_ptr && new_size
*/
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	unsigned char	*old_ptr;
	unsigned char	*new_ptr;
	size_t			alloc_size;
	size_t			i;

	old_ptr = (unsigned char *)ptr;
	alloc_size = new_size;
	if (!new_size && old_ptr)
		alloc_size = 1;
	new_ptr = malloc(alloc_size);
	if (!new_ptr)
		return (ptr);
	if (new_size && old_ptr)
	{
		i = 0;
		while (i < old_size && i < new_size)
		{
			new_ptr[i] = old_ptr[i];
			++i;
		}
	}
	free(ptr);
	return (new_ptr);
}

size_t	expand_vector(char **ptr, size_t old_size)
{
	size_t	new_size;

	new_size = old_size << 1;
	*ptr = ft_realloc(*ptr, old_size, new_size);
	return (new_size);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	cpsize;

	src_len = 0;
	while (src[src_len])
		++src_len;
	if (dstsize != 0)
	{
		cpsize = dstsize - 1;
		while (*src && cpsize > 0)
		{
			*dst = *src;
			++dst;
			++src;
			--cpsize;
		}
		*dst = '\0';
	}
	return (src_len);
}

static int	read_str(int fd, char buf[])
{
	size_t	r;

	r = read(fd, buf, BUFSIZE);
	if (r < 0)
		return (-1);
	buf[r] = '\0';
	return (r);
}

/*
 * buf[BUFSIZE]: contain BUFSIZE characters
 * line:         join characters in {buf} and make a line
 *
 * add characters from {buf} to {line} until \n
 * delete the characters added to {line} from {buf}, move the leftovers forward, and nul-terminate
 * read a new set of BUFSIZE characters if buf[0] == nul
 * break the loop if read <= 0 or \n
 */
char	*get_next_line(int fd)
{
	static char	buf[BUFSIZE + 1];
	char		*line;
	size_t		mem_size;
	size_t		k;
	size_t		i;

	line = NULL;
	mem_size = 1;
	k = 0;
	while (buf[0])
	{
		i = 0;
		while (buf[i])
		{
			if (mem_size == k + i + 1)
				mem_size = expand_vector(&line, mem_size);
			line[k + i] = buf[i];
			if (buf[i++] == '\n')
			{
				ft_strlcpy(buf, buf + i, BUFSIZE + 1);
				line[k + i] = '\0';
				return (line);
			}
		}
		k += i;
		line[k] = '\0';
		if (read_str(fd, buf) == -1)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}
