/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:27:41 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 15:36:45 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*byte;
	unsigned char	value;

	byte = (unsigned char *)b;
	value = (unsigned char)c;
	while (len > 0)
	{
		*byte = value;
		byte++;
		len--;
	}
	return (b);
}
//void b is a pointer for the memory block to be filled.
//int c is the value
//len the number of bytes to set
//converting b to unsigned char to work with individual bytes
//converting c to unsigned char to work with byte represantion
//looping until len reaches 0
//setting the current byte to the value we want to change it into.
//moving to the next byte while also decreasing the count.