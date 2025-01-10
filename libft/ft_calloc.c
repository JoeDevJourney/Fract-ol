/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:51:23 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 12:36:11 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytes;
	void	*ptr;

	bytes = count * size;
	if (size && ((bytes / size) != count))
		return (NULL);
	ptr = malloc(bytes);
	if (NULL == ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}

//void *, pointer to the allocated memory.
//count, numbers of allocated (reserved space/reserving space) elements.
//size, how big the elements are.
//bytes, the entirety of how many allocated bytes there are.
//ptr, points at the storage area.
// bytes = count * size, to find out how much total of space we need.
//bytes/size != count is to make sure there are no overflows and
// that they correspond to the original.
// the size && also makes sure that it cant be null.
//ptr = malloc(bytes) reserving space for the entire byte count
//if malloc doesnt return any memory, returning NULL.
//NULL testing if pointer is null.
//if allocation done correctly, ft_bzero puts the memory to 0,
//getting rid of the old data.