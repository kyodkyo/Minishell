/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:34:18 by woonshin          #+#    #+#             */
/*   Updated: 2023/10/29 15:02:03 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_digit(int n);
static void		fill_num(char *result, long num, int digit, int cursor);

char	*ft_itoa(int n)
{
	int		digit;
	int		print_size;
	int		cursor;
	long	num;
	char	*result;

	num = n;
	digit = get_digit(num);
	print_size = digit + 1;
	if (n < 0)
	{
		print_size += 1;
		num *= -1;
	}
	result = (char *)ft_calloc(sizeof(char), print_size);
	if (result == NULL)
		return (NULL);
	cursor = print_size - 2;
	fill_num(result, num, digit, cursor);
	if (n < 0)
		result[0] = '-';
	return (result);
}

static void	fill_num(char *result, long num, int digit, int cursor)
{
	while (digit > 0)
	{
		result[cursor--] = "0123456789"[num % 10];
		num /= 10;
		digit--;
	}
}

static int	get_digit(int n)
{
	int	digit;

	digit = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}
