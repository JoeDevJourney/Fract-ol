/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:21:45 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 15:28:11 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	typedef unsigned char byte;
	if (len == 0 || (src == NULL && dst == NULL))
		return (dst);
	if (dst > src)
		while (len--)
			*((byte *)dst + len) = *((byte *)src + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
//size_t len the number of bytes to copy.
//if len is 0 or both is 0, just return dst because there is nothing.
//while len-- it runs until len becomes 0.
//if dst has a lower memory, it copies the bytes from src to dst.