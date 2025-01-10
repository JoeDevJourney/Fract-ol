/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:22:23 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/31 10:14:48 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen_printf(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_putstrprint(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		s = "(null)";
	if (write(1, s, ft_strlen_printf(s)) < 0)
		return (-1);
	len += ft_strlen_printf(s);
	return (len);
}
