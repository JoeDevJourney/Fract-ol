/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:49:50 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 11:48:41 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	isneg;
	int	i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

// the \t for skipping tabs, \n for newline, \r to go back
// to the beginning of the line, \v is vertical tab
// \f is to go to the next page.
// plus is getting skipped.
//if minus, isneg is turning negative to display negative
//numbers.
//looping through the number in the string and is building the num
//step by step.
//str[i] - 0 is converting it into its numeric form
//num * 10 is helping building the number step by step
// num * isneg is turning it into the right form, either + or -