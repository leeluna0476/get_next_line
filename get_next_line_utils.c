/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:55:39 by seojilee          #+#    #+#             */
/*   Updated: 2025/01/30 15:24:40 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	expand_vector(t_vector *vec)
{
	const size_t	new_size = vec->size << 1;

	vec->line = ft_realloc(vec->line, vec->size, new_size);
	if (!vec->line)
		vec->size = 0;
	else
		vec->size = new_size;
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const size_t	src_len = ft_strlen(src);
	size_t			cpsize;

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
