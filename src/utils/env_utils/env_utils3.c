/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:30:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 21:41:43 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

void	to_lowercase(char *str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
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

t_env	*ft_envnew(void)
{
	t_env	*new;

	new = ft_calloc(1, sizeof(t_env));
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
