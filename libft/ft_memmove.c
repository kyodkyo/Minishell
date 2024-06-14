/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:33:40 by woonshin          #+#    #+#             */
/*   Updated: 2023/10/29 14:57:50 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_char;
	char	*src_char;

	if (dst == 0 && src == 0)
		return (NULL);
	i = 0;
	dst_char = (char *)dst;
	src_char = (char *)src;
	while (i < len)
	{
		if (dst <= src)
			dst_char[i] = src_char[i];
		else
			dst_char[len - 1 - i] = src_char[len - 1 - i];
		i++;
	}
	return (dst);
}
