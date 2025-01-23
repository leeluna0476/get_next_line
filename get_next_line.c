/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:39:05 by seojilee          #+#    #+#             */
/*   Updated: 2025/01/23 10:23:32 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

/*
copy 조건:
old_ptr && new_size
*/
static void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
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

char	*get_next_line(int fd)
{
	(void)fd;
	return (NULL);
}
