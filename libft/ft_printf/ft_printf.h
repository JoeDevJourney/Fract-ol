/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:57:25 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/31 10:13:20 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int			ft_printf(const char *str, ...);
int			ft_putstrprint(char *s);
int			ft_printp(size_t value);
int			ft_printid(va_list args);
int			ft_printu(va_list args);
int			ft_printhex(unsigned int value, char specifier);
int			ft_putchar(char c);
#endif