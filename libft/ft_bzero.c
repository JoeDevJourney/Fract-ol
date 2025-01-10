/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:18:19 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 12:05:40 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr++ = 0;
		n--;
	}
}

//void s points tot the memory you want to set to 0
//size t n indicates how many bytes are getting set to 0
//unsigned char is there to work from byte to byte.
//while loop to go through as long as its bigger than 0.
//*ptr++ = 0, the current byte is getting set to 0,
//jumps to the next byte.
// n--, reduces the amount of bytes left that needs to be set to 0.