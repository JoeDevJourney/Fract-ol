/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:01:44 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 17:54:16 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strdup(const char *s1)
{
	char		*str;
	size_t		buf_size;

	buf_size = ft_strlen(s1) + 1;
	str = (char *)malloc(buf_size);
	if (NULL == str)
		return (NULL);
	ft_strlcpy(str, s1, buf_size);
	return (str);
}
//duplicating the string by allocating the memory
//calculating the length of input string plus one '\0'
//allocating memory for the duplicate string
//if memory allocation failed, returning NULL
//copy the content of input string to pointer str
//returning the duplicate string