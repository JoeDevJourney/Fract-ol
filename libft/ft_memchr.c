/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:39:58 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 14:10:11 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *buffer, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)buffer + i) == (unsigned char)c)
			return ((void *)((unsigned char *)buffer + i));
		++i;
	}
	return (NULL);
}
//its looking for a specific character inside a buffer.
//i is used to go through the buffer for the loop.
//as long as i is smaller than n it goes through it.
//converting buffer into an unsigned char and then
//its moving i bytes. if i = 2, its showing the third byte.