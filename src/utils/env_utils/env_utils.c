/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:24:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 18:58:57 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

char	*get_next_key(t_list *env_list, char *prev)
{
	char	*result;

	result = NULL;
	while (env_list)
	{
		if (!result && cmp_str(prev, ((t_env *)env_list->content)->key) < 0)
			result = ((t_env *)env_list->content)->key;
		else
		{
			if (cmp_str(prev, ((t_env *)env_list->content)->key) < 0
				&& cmp_str(result, ((t_env *)env_list->content)->key) > 0)
				result = ((t_env *)env_list->content)->key;
		}
		env_list = env_list->next;
	}
	return (result);
}

t_env	*find_by_key(t_list *env_list, char *target_key)
{
	t_list	*list;

	list = env_list;
	while (list)
	{
		if (cmp_str(((t_env *)list->content)->key, target_key) == 0)
			return (list->content);
		list = list->next;
	}
	return (NULL);
}

void	update_env(t_env *env, char *key, char *value)
{
	char	*data;

	if (!value)
		data = ft_strdup(key);
	else
	{
		data = combine_str(ft_strdup(key), "=");
		data = combine_str(data, ft_strdup(value));
	}
	if (!data)
		memory_error();
	env->data = data;
	env->key = ft_strdup(key);
	if (value)
		env->value = ft_strdup(value);
}

void	add_new_env(t_list **env_list, char *key, char *value)
{
	t_env	*new_env;
	t_list	*tmp;

	new_env = ft_envnew();
	if (!new_env)
		memory_error();
	tmp = ft_lstnew(new_env);
	if (!tmp)
		memory_error();
	update_env(new_env, key, value);
	ft_lstadd_back(env_list, tmp);
}

void	add_env(t_list **env_list, char *key, char *value)
{
	t_env	*new_env;

	new_env = find_by_key(*env_list, key);
	if (!new_env)
		add_new_env(env_list, key, value);
	else if (value)
	{
		free(new_env->data);
		free(new_env->key);
		if (new_env->value)
			free(new_env->value);
		update_env(new_env, key, value);
	}
}
