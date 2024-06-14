/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:34:54 by woonshin          #+#    #+#             */
/*   Updated: 2023/10/29 15:01:15 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	size_t			s_len;
	size_t			alloc_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	alloc_len = len;
	if (s_len <= start)
		alloc_len = 0;
	else if (s_len - start < len)
		alloc_len = s_len - start;
	result = (char *)ft_calloc(alloc_len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (0 < alloc_len)
		ft_strlcpy(result, s + start, alloc_len + 1);
	return (result);
}
