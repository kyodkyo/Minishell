/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:29:32 by woonshin          #+#    #+#             */
/*   Updated: 2023/11/06 20:28:00 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow_check_64(const char *str, char sign_bit);
static int	ft_isspace(char c);
static char	get_sign_bit(const char *str, size_t *i);

int	ft_atoi(const char *str)
{
	size_t		i;
	char		sign_bit;
	char		overflow_result;
	int			result;

	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	sign_bit = get_sign_bit(str, &i);
	overflow_result = overflow_check_64(str + i, sign_bit);
	if (overflow_result != 1)
		return (overflow_result);
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		if (sign_bit == 1)
			result -= str[i] - '0';
		else
			result += str[i] - '0';
		i++;
	}
	return (result);
}

static int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

static int	overflow_check_64(const char *str, char sign_bit)
{
	if (ft_strlen(str) < 19)
		return (1);
	if (sign_bit == 0 && ft_strncmp(str, "9223372036854775807", 19) > 0)
		return (-1);
	if (sign_bit == 1 && ft_strncmp(str, "9223372036854775808", 19) > 0)
		return (0);
	return (1);
}

static char	get_sign_bit(const char *str, size_t *i)
{
	char	sign_bit;

	sign_bit = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign_bit = 1;
		*i = *i + 1;
	}
	return (sign_bit);
}
