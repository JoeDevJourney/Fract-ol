/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:35:46 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/31 10:13:59 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pointer_recursive(unsigned long num)
{
	int		len;
	int		result;
	char	*digit;

	len = 0;
	digit = "0123456789abcdef";
	if (num >= 16)
	{
		result = pointer_recursive(num / 16);
		if (result == -1)
			return (-1);
		len += result;
	}
	result = ft_putchar(digit[num % 16]);
	if (result == -1)
		return (-1);
	len += result;
	return (len);
}

int	ft_printp(size_t value)
{
	int		len;
	char	result;

	len = 0;
	len += ft_putstrprint("0x");
	if (len < 0)
		return (-1);
	if (value == 0)
	{
		result = ft_putstrprint("0");
		if (result == -1)
			return (-1);
		len += result;
	}
	else
	{
		result = pointer_recursive(value);
		if (result == -1)
			return (-1);
		len += result;
	}
	return (len);
}
