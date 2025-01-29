/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:39:12 by seojilee          #+#    #+#             */
/*   Updated: 2025/01/29 14:54:07 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFSIZE
#  define BUFSIZE 64
# endif

# include <stdlib.h>

/*
 * The initial size must be 1.
 */
typedef struct s_vector
{
	char	*line;
	size_t	size;
}	t_vector;

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	expand_vector(struct s_vector *vec);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);

#endif
