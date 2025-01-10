/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:38:56 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/31 10:13:41 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(int num)
{
	int	len;
	int	result;

	len = 0;
	if (num == -2147483648)
		return (ft_putstrprint("-2147483648"));
	if (num < 0)
	{
		result = ft_putchar('-');
		if (result == -1)
			return (-1);
		len += result;
		num = -num;
	}
	if (num >= 10)
	{
		result = ft_putnbr(num / 10);
		if (result == -1)
			return (-1);
		len += result;
	}
	len += ft_putchar((num % 10) + '0');
	return (len);
}

int	ft_printid(va_list args)
{
	int	num;

	num = va_arg(args, int);
	return (ft_putnbr(num));
}
