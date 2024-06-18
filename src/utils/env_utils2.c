/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:30:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/18 14:51:19 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	to_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

t_env	*ft_envnew(void)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->data = NULL;
	new->key = NULL;
	new->value = NULL;
	return (new);
}

int	cmp_str(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strlen(s2) * -1);
	else if (!s2)
		return (ft_strlen(s1));
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
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
	*key = get_substring(data, 0, i);
	*value = get_substring(data, i + 1, len - i);
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
			error();
		tmp = make_new_node(env);
		if (!tmp)
			error();
		env->data = dup_str(*envp);
		if (!env->data)
			error();
		init_split_key_value(env->data, &(env->key), &(env->value));
		list_add_back(&env_list, tmp);
		envp++;
	}
	return (env_list);
}
