/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:44:21 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 18:33:35 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	buffer;
	size_t	i;
	char	*ptr;

	i = 0;
	if (NULL == s1 || NULL == s2)
		return (NULL);
	buffer = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(buffer);
	if (NULL == ptr)
		return (NULL);
	while (*s1)
		*(ptr + i++) = *s1++;
	while (*s2)
		*(ptr + i++) = *s2++;
	*(ptr + i) = '\0';
	return (ptr);
}
//chain two strings s1 and s2 into a new string.
//checks if either string is NULL, if so return NULL
//getting the length of new string + 1 for '\0'
//allocating memory for new string
//if allocation failed, returning NULL
//looping for each char in s1
//copying each char from s1 to ptr and incrementing both i and s1
//doing the same thing for string 2
//adding '\0' at the end of the new string and returning new string.
