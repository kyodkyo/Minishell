/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:44:56 by woonshin          #+#    #+#             */
/*   Updated: 2023/10/29 15:41:04 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_count(char const *s, char c);
static int	split_word(char const *s, const char c, char **words);
static int	free_array(char **words, int x);

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**result;

	if (s == NULL)
		return (NULL);
	word_count = get_word_count(s, c);
	result = (char **)ft_calloc((word_count + 1), sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (split_word(s, c, result) != 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

static int	get_word_count(char const *s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	if (s[0] == '\0')
		return (0);
	else if (s[0] != c)
		word_count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			word_count++;
		i++;
	}
	return (word_count);
}

static int	split_word(char const *s, const char c, char **words)
{
	size_t	start;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			start = i + 1;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			words[x] = ft_substr(s, start, (i + 1) - start);
			if (words[x] == NULL)
			{
				free_array(words, x);
				return (-1);
			}
			x++;
		}
		i++;
	}
	return (0);
}

static int	free_array(char **words, int x)
{
	while (0 <= x)
	{
		free(words[x]);
		x--;
	}
	return (1);
}
