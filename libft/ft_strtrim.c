/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:25 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/17 11:19:05 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed;

	if (NULL == s1 || NULL == set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		++start;
	while (end >= 0 && ft_strchr(set, *(s1 + end)))
		--end;
	if (start > end)
		return (ft_strdup(""));
	trimmed = malloc((end - start) + 2);
	if (NULL == trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, (end - start) + 2);
	return (trimmed);
}
//s1 is string that needs to be trimmed
//set is the chars that needs to be trimmed from s1
//NULL because trimming cannot be performed.
//if string is empty, returns a duplicate.
//the -1 is for the '\0'. so we have the end of the string.
//while loop to find a char that is not in set. it does start++
//until it reaches a char that is not in set.
//while loop to find the last char that is not in end.
//if start is bigger than end, all chars have been trimmed.
//afterwards allocating memory.
//if failed, return NULL.
//copy and returning the timmed part