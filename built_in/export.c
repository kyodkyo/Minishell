/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:30:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/06 22:26:46 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	combine_declare_x(t_list *env_list, char *key)
{
	char	*res;
	t_env	*env;

	res = NULL;
	env = find_by_key(env_list, key);
	write(1, "declare -x ", 11);
	write(1, key, ft_strlen(key));
	if (env->value)
	{
		write(1, "=\"", 2);
		write(1, env->value, ft_strlen(env->value));
		write(1, "\"", 1);
	}
	write(1, "\n", 1);
}

char	*get_next_key(t_list *env_list, char *prev)
{
	char	*result;

	result = NULL;
	while (env_list)
	{
		if (!result && ft_strcmp(prev, ((t_env *)env_list->content)->key) < 0)
			result = ((t_env *)env_list->content)->key;
		else
		{
			if (ft_strcmp(prev, ((t_env *)env_list->content)->key) < 0
				&& ft_strcmp(result, ((t_env *)env_list->content)->key) > 0)
				result = ((t_env *)env_list->content)->key;
		}
		env_list = env_list->next;
	}
	return (result);
}

void	export_no_argv(t_list *env_list)
{
	int		i;
	int		size;
	char	*prev_key;
	char	*cur_key;

	i = 0;
	size = ft_lstsize(env_list);
	prev_key = NULL;
	cur_key = NULL;
	while (i < size)
	{
		cur_key = get_next_key(env_list, prev_key);
		combine_declare_x(env_list, cur_key);
		prev_key = cur_key;
		i++;
	}
}

void	export_split_key_value(char *data, char **key, char **value)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(data);
	while (data[i] && data[i] != '=')
		i++;
	*key = ft_substr(data, 0, i);
	if (len - i)
		*value = ft_substr(data, i + 1, len - i);
	else
		*value = NULL;
}

void	export(int argc, char **argv, char **envp, t_list *env_list)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	if (!argv[1])
		export_no_argv(env_list);
	while (argv[++i])
	{
		key = NULL;
		value = NULL;
		export_split_key_value(argv[i], &key, &value);
		if (is_valid_key(key))
			error();
		else
			add_env(&env_list, key, value);
		free(key);
		free(value);
	}
}
