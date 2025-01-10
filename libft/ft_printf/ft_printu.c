/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:05:07 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/22 16:09:32 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsigned_rec(unsigned int num)
{
	int	len;
	int	results;

	len = 0;
	if (num >= 10)
	{
		results = unsigned_rec(num / 10);
		if (results == -1)
			return (-1);
		len += results;
	}
	len += ft_putchar((num % 10) + '0');
	return (len);
}

int	ft_printu(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (unsigned_rec(num));
}
