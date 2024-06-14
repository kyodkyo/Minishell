/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:29:46 by woonshin          #+#    #+#             */
/*   Updated: 2023/10/29 15:46:58 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*result;

	len = 0;
	start = 0;
	end = 0;
	while (s1[start] != '\0' && is_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (end != 0)
		end--;
	while (end != 0 && is_set(s1[end], set))
		end--;
	len = end - start + 1;
	if (start > end || s1[0] == '\0')
		len = 0;
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, ((void *)s1 + start), len);
	result[len] = '\0';
	return (result);
}

static int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
