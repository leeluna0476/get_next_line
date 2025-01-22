/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:39:05 by seojilee          #+#    #+#             */
/*   Updated: 2025/01/22 11:44:17 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		++s;
		++i;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	cpsize;

	src_len = ft_strlen(src);
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

char	*get_next_line(int fd)
{
	(void)fd;
	return (NULL);
}
