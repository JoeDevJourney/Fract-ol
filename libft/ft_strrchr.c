/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:59:44 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/17 11:01:15 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if ((char)c == s[len])
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
//finding the last occurence of a char in string
//if current char matches c, returning to its pos in string
//by casting the pointer
//returning NULL if 404