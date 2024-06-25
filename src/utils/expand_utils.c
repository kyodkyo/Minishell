/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:33:08 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 18:46:03 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_utils.h"

int	is_valid(char *s, int i)
{
	if (s[i] == '$')
	{
		if (s[i + 1] == '\0')
			return (1);
		if (s[i + 1] && s[i + 1] == '$')
			return (1);
		if (s[i + 1] && s[i + 1] == '_')
			return (1);
		if (s[i + 1] && s[i + 1] == '?')
			return (1);
		if (s[i + 1] && (s[i + 1] >= 'A' || s[i + 1] <= 'Z'))
			return (1);
		if (s[i + 1] && (s[i + 1] >= 'a' || s[i + 1] <= 'z'))
			return (1);
	}
	return (0);
}

int	find_start_pos(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_valid(s, i))
			return (i);
		i++;
	}
	return (-1);
}

int	find_end_pos(char *s, int i)
{
	if (s[i] == '$')
		return (i - 1);
	if (s[i] == '?')
		return (1);
	while ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')
		|| s[i] == '_' || (s[i] >= '0' && s[i] <= '9'))
		i++;
	return (i - 1);
}

char	*get_env_value(t_list *env_list, char *key)
{
	char	*result;
	t_env	*env;

	env = find_by_key(env_list, key);
	if (!env)
		result = ft_strdup("");
	else
		result = ft_strdup(env->value);
	if (!result)
		memory_error();
	return (result);
}
