/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 06:13:46 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 18:47:31 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*str_join_len(void *dst, const void *src, size_t len)
{
	size_t	index;

	index = 0;
	if (!dst && !src)
		return (dst);
	while (index < len)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}

char	*combine_str(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (s1 == 0 && s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (res == NULL)
		memory_error();
	str_join_len(res, s1, s1_len);
	copy_str_len(res + s1_len, s2, s2_len + 1);
	return (res);
}

int	copy_str_len(char *dst, const char *src, size_t dstsize)
{
	int		src_len;
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

int	compare_str(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*get_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s || !len || (unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		memory_error();
	copy_str_len(res, &s[start], len + 1);
	return (res);
}
