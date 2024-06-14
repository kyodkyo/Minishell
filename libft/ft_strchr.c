/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:12:13 by woonshin          #+#    #+#             */
/*   Updated: 2023/10/27 21:09:59 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*result;
	char	char_c;

	result = (char *)s;
	char_c = (char)c;
	while (*result != '\0' && *result != char_c)
		result++;
	if (*result == char_c)
		return (result);
	return (NULL);
}
