/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:58:45 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 17:59:15 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
//applying a function (f)to each char in the string
//s is input string, f a function pointer that takes an
//unsigned int and char pointer.
//checking if s or f are NULL. If either is NULL, returning to
//prevent errors.
//looping through each char of string s until end
//calling the function f, passing through current index and chara