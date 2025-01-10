/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:22:54 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 13:26:57 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n)
	{
		++ count;
		n /= 10;
	}
	return (count);
}
//ft_len is calculating the length of the numbers.
//static int, meaning it can only be visible within data, where its used.
//count is for knowing the number of digits.
//if n is 0 or negativ, count gets inreased to take sign,
// or zero into account
//while loop, goes through n to know how big the number is,
//example for 5000, 4

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = ft_len(n);
	ptr = malloc(len + 1);
	if (NULL == ptr)
		return (NULL);
	ptr[len] = '\0';
	if (0 == n)
		ptr[0] = '0';
	else if (n < 0)
		ptr[0] = '-';
	while (n)
	{
		if (n < 0)
			ptr[--len] = (~(n % 10) + 1) + 48;
		else
			ptr[--len] = (n % 10) + 48;
		n /= 10;
	}
	return (ptr);
}

//it makes space for the number plus 1 (for the end sign)
//if there is no space, it returns NULL
//put the end sign to show the end of the number
//while loop, it goes from the last number up to the first.
// the 48 makes sure its converted correctly.
// the --len is to reduce the length of the strong and puts the
//the number into the right place.