/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:22:54 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/18 14:51:21 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	change_to_value(char *result, char *front, char *env_value, char *back)
{
	int		i;
	char	*front_str;
	char	*back_str;

	front_str = front;
	back_str = back;
	i = 0;
	while (*front)
		*(result++) = *(front++);
	while (*env_value)
		*(result++) = *(env_value++);
	while (*back)
		*(result++) = *(back++);
	*result = '\0';
	free(front_str);
	free(back_str);
}

char	*make_expand_data(t_list *env_list, char *origin, int start, int end)
{
	int		len;
	char	*key;
	char	*value;
	char	*result;

	key = get_substring(origin, start + 1, end - start);
	value = get_value(env_list, key);
	len = ft_strlen(origin) - (end - start + 1) + ft_strlen(value);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		error();
	change_to_value(result, get_substring(origin, 0, start),
		value, get_substring(origin, end + 1, ft_strlen(origin)));
	free(key);
	free(value);
	return (result);
}

char	*expand_env(t_list *env_list, char *origin)
{
	int		start;
	int		end;
	char	*temp;
	char	*expand_str;

	printf("origin: %s\n", origin);
	expand_str = dup_str(origin);
	start = find_start_pos(expand_str);
	while (start != -1)
	{
		end = find_end_pos(expand_str, start + 1);
		temp = expand_str;
		expand_str = make_expand_data(env_list, expand_str, start, end);
		free(temp);
		start = find_start_pos(expand_str);
	}
	return (expand_str);
}
