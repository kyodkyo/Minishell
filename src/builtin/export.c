/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:30:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 01:30:39 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(t_ASTNode *node, t_list *env_list, t_io *io_handler)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	if (!node->value[1])
		export_no_argv(env_list, io_handler);
	while (node->value[++i])
	{
		key = NULL;
		value = NULL;
		export_split_key_value(&node->value[i], &key, &value);
		if (is_valid_key(key))
			printf("error\n");
		else
			add_env(&env_list, key, value);
		free(key);
		free(value);
	}
}
