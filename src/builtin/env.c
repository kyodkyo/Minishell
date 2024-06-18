/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:29:13 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/18 14:24:56 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	env(int argc, char **argv, char **envp, t_list *env_list)
{
	char	*data;

	while (env_list)
	{
		if (((t_env *)(env_list->content))->value)
		{
			data = ((t_env *)(env_list->content))->data;
			write(1, data, ft_strlen(data));
			write(1, "\n", 1);
		}
		env_list = env_list->next;
	}
}
