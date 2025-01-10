/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:02:17 by jbrandt           #+#    #+#             */
/*   Updated: 2024/10/16 17:32:26 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	safe_malloc(char **token_v, int position, size_t buffer)
{
	int	i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (NULL == token_v[position])
	{
		while (i < position)
			free(token_v[i++]);
		free(token_v);
		return (1);
	}
	return (0);
}
//allocating memory for a specific position in an array of strings.
//if its fails, free it all and return an error code.
//if malloc returns NUll, while loop through all positions in token_v.
//frees the memory from each position.
//frees the entire array token_v

int	fill(char **token_v, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (safe_malloc(token_v, i, len + 1))
				return (1);
			ft_strlcpy(token_v[i], s - len, len + 1);
		}
		++i;
	}
	return (0);
}
//splitting a string, here s and storing them in an array token_v
//while s to loop through the string until '\0'
//while loop skipping over any delimeters
//while loop to calculate the current length by iterating
//through them until another delimeter or end of string.
//allocating memorz for token, if fails return 1.
//with strlcpy to copy the token into memory.
//s - len points to start of token and len + 1 includes the null
//terminator.

size_t	count_tokens(char const *s, char delimeter)
{
	size_t	tokens;
	int		inside_token;

	tokens = 0;
	while (*s)
	{
		inside_token = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			if (!inside_token)
			{
				++tokens;
				inside_token = 42;
			}
			++s;
		}
	}
	return (tokens);
}
//counting the tokens in the string s
//char delimeter used to split the string.
//size t token to count number of tokens.
//looping through the entire string until the end
//the first while is to skip any delimeters.
//the second while is to loop through characters until delimeter
//or end of string
//if we are not already inside token, we set a flag to indicate that we are
//inside a token with inside_token = 42
// in the end we return how many tokens we have.

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**token_v;

	if (NULL == s)
		return (NULL);
	tokens = 0;
	tokens = count_tokens(s, c);
	token_v = malloc((tokens + 1) * sizeof(char *));
	if (NULL == token_v)
		return (NULL);
	token_v[tokens] = NULL;
	if (fill(token_v, s, c))
		return (NULL);
	return (token_v);
}
//splitting a string into tokens unsing delimeter and store them in array
//if input string is null, it returns null, nothing to split
//calling count tokens to know how many tokens there will be
//allocating memory for the array. the + 1 is for the null terminator at
//end.
//checking if memory allocation failed. if so, it returns null.
//setting the last element of the array to null, marking the end.
//calling fill to fill the array with tokens.
//if error, returns NULL.