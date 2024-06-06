/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:42:17 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/06 21:55:08 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

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

int	ft_strcmp(char *s1, char *s2)
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
	*key = ft_substr(data, 0, i);
	*value = ft_substr(data, i + 1, len - i);
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
		tmp = ft_lstnew(env);
		if (!tmp)
			error();
		env->data = ft_strdup(*envp);
		if (!env->data)
			error();
		init_split_key_value(env->data, &(env->key), &(env->value));
		ft_lstadd_back(&env_list, tmp);
		envp++;
	}
	return (env_list);
}
