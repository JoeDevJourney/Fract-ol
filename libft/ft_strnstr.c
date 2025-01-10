/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:44:08 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/17 10:15:17 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (!*needle || (NULL == hay && !len))
	{
		return ((char *)hay);
	}
	while (*(hay + a) && a < len)
	{
		b = 0;
		while (*(hay + a + b) == *(needle + b) && (a + b) < len)
		{
			if (0 == *(needle + b + 1))
			{
				return ((char *)hay + a);
			}
			++b;
		}
		++a;
	}
	return (NULL);
}
//hay is gonna be the search string
//needle the substring we are searching for
//len how manz char we search in hay
//if needle is empty or hay is NULL it returns hay.
//looping through each char in hay as long as its smaller then len
//to not reach '\0'
//second loop is to compare chars of needle with hay
//if the end of needle is reached, we return to the starting pos
//of match in hay
//b is to move char in needle
//a is to move char in hay
//returning NULL if there is no match