/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:45:30 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/17 09:56:02 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
	{
		return (0);
	}
	while (*s1 == *s2 && --n && *s1)
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
//comparing s1 and s2 by n many chars
//if there is nothing to compare, returning 0.
//continues to compare as long as the chars in the current pos
//are equal, there are still chars left to compare,
//neither has reached '\0'.
//after loop, if chars are different, returning the current different chars