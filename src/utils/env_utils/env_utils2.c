/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:54:19 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 18:45:34 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

void	free_env_node(t_list **node)
{
	t_env	*env;

	env = (t_env *)(*node)->content;
	free(env->data);
	free(env->key);
	if (env->value)
		free(env->value);
	free(env);
	free(*node);
	*node = NULL;
}

void	remove_key_value(t_list **env_list, t_list *list, t_list *cur)
{
	if (!list)
		*env_list = cur->next;
	else
		list->next = cur->next;
	free_env_node(&cur);
}

void	unset_env(t_list **env_list, char *target_key)
{
	t_list	*cur;
	t_list	*list;

	cur = *env_list;
	list = NULL;
	while (cur)
	{
		if (cmp_str(((t_env *)(cur->content))->key, target_key) == 0)
		{
			remove_key_value(env_list, list, cur);
			break ;
		}
		list = cur;
		cur = cur->next;
	}
}

void	init_split_key_value(char *data, char **key, char **value)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(data);
	while (data[i])
	{
		if (data[i] == '=')
			break ;
		i++;
	}
	*key = get_substr(data, 0, i);
	*value = get_substr(data, i + 1, len - i);
}

t_list	*init_envp(char **envp)
{
	t_env	*env;
	t_list	*tmp;
	t_list	*env_list;

	env_list = NULL;
	while (*envp)
	{
		env = ft_envnew();
		if (!env)
			memory_error();
		tmp = ft_lstnew(env);
		if (!tmp)
			memory_error();
		env->data = ft_strdup(*envp);
		if (!env->data)
			memory_error();
		init_split_key_value(env->data, &(env->key), &(env->value));
		ft_lstadd_back(&env_list, tmp);
		envp++;
	}
	return (env_list);
}
