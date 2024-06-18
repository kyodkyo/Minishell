/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 06:15:31 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/18 14:51:23 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*dup_str(const char *s1)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = ((char *)s1)[i];
		i++;
	}
	res[i] = '\0';
	return (res);
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
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (res == NULL)
		return (NULL);
	join_str(res, s1, s1_len);
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

char	*get_substring(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s || !len || (unsigned int)ft_strlen(s) <= start)
		return (dup_str(""));
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	copy_str_len(res, &s[start], len + 1);
	return (res);
}
