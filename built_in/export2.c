/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:45:08 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/06 01:46:51 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	update_env(t_env *env, char *key, char *value)
{
	char	*data;

	if (!value)
		data = ft_strdup(key);
	else
	{
		data = ft_strjoin(ft_strdup(key), "=");
		data = ft_strjoin(data, ft_strdup(value));
	}
	if (!data)
		error();
	env->data = data;
	env->key = key;
	if (value)
		env->value = value;
}

void	add_new_env(t_list **env_list, char *key, char *value)
{
	t_env	*new_env;
	t_list	*tmp;

	new_env = ft_envnew();
	if (!new_env)
		error();
	tmp = ft_lstnew(new_env);
	if (!tmp)
		error();
	update_env(new_env, key, value);
	ft_lstadd_back(env_list, tmp);
}

t_env	*find_by_key(t_list *env_list, char *target_key)
{
	t_list	*list;

	list = env_list;
	while (list)
	{
		if (ft_strcmp(((t_env *)list->content)->key, target_key) == 0)
			return (list->content);
		list = list->next;
	}
	return (NULL);
}

void	add_env(t_list **env_list, char *key, char *value)
{
	t_env	*new_env;

	new_env = find_by_key(*env_list, key);
	if (!new_env)
		add_new_env(env_list, key, value);
	else if (new_env && value)
	{
		free(new_env->data);
		free(new_env->key);
		if (new_env->value)
			free(new_env->value);
		update_env(new_env, key, value);
	}
}
