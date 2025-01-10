/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:32:36 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 18:57:56 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (NULL == dest || NULL == src || !dstsize)
	{
		return (len);
	}
	while (*src && -- dstsize)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (len);
}
//it copies the string from src to dest to ensure that the dst buffer
//doesnt overflow and is nulled.
//calculating the length of the src string.
//checking if dest or src is NULL, if so, returning the length of src
//looping through src string until end  or until dst buffer full.
//copying each char from src to dst and move to next char
//adding '\0' to terminate it.
//returning length of src.