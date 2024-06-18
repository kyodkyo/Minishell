/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:54:19 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/18 14:54:44 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

int	is_valid_key(char *key)
{
	int	i;

	i = -1;
	if ('0' <= key[0] && key[0] <= '9')
		return (1);
	while (key[++i])
	{
		if (!(('a' <= key[i] && key[i] <= 'z')
				|| ('A' <= key[i] && key[i] <= 'Z')
				|| ('0' <= key[i] && key[i] <= '9') || (key[i] == '_')))
			return (1);
	}
	return (0);
}
