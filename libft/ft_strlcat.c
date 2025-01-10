/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:03:02 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 18:42:54 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (NULL == dst && 0 == dstsize)
		return (src_len);
	dest_len = ft_strlen(dst);
	if (dest_len >= dstsize)
		return (src_len + dstsize);
	else
		dstsize -= dest_len;
	ft_strlcpy(dst + dest_len, src, dstsize);
	return (dest_len + src_len);
}
//chaining 2 strings and making sure it doesn=t exceed a specified
//size.
//calculating the source length
//if dst is NULL and dstsize is 0, it returns the length of src.
//calculating the dst length
//if dst len is bigger or equal to dstsize, it returns the sum of
//source length and dstsize, this shows that the dst buffer is too small
//to hold the chained strings.
//adjusting the buffer size.
//copying source to destination
//returning total length