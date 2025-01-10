/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:24:01 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/22 13:40:59 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex(size_t value, int uppercase)
{
	int		len;
	int		result;
	char	*num;

	if (uppercase)
		num = "0123456789ABCDEF";
	else
		num = "0123456789abcdef";
	len = 0;
	if (value >= 16)
	{
		result = ft_hex(value / 16, uppercase);
		if (result == -1)
			return (-1);
		len += result;
	}
	result = ft_putchar(num[value % 16]);
	if (result == -1)
		return (-1);
	len += result;
	return (len);
}

int	ft_printhex(unsigned int value, char specifier)
{
	int				uppercase;
	int				temp_len;

	uppercase = (specifier == 'X');
	temp_len = ft_hex(value, uppercase);
	if (temp_len < 0)
		return (-1);
	else
		return (temp_len);
}
