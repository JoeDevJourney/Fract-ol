/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:09:38 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/31 10:13:26 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char c, va_list value, int *counter)
{
	int		temp_len;

	temp_len = 0;
	if (c == 'c')
		temp_len = ft_putchar(va_arg (value, int));
	else if (c == 's')
		temp_len = ft_putstrprint(va_arg(value, char *));
	else if (c == 'p')
		temp_len = ft_printp((size_t)va_arg(value, void *));
	else if (c == 'd' || c == 'i')
		temp_len = ft_printid(value);
	else if (c == 'u')
		temp_len = ft_printu(value);
	else if (c == 'x' || c == 'X')
		temp_len = ft_printhex(va_arg(value, unsigned int), c);
	else if (c != 0)
		temp_len = ft_putchar(c);
	*counter += temp_len;
	if (temp_len < 0)
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	char	*str;
	va_list	args;

	counter = 0;
	str = (char *)format;
	va_start(args, format);
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) && (ft_type(*(++str), args, &counter) < 0))
				return (-1);
		}
		else
		{
			if (ft_putchar(*str) < 0)
				return (-1);
			counter++;
		}
		str++;
	}
	va_end(args);
	return (counter);
}
