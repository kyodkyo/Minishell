/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:30:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 21:49:20 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "utils.h"

void	export(t_ASTNode *node, t_list *env_list)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	if (!node->cmd->argv[1])
		export_no_argv(env_list);
	while (node->cmd->argv[++i])
	{
		key = NULL;
		value = NULL;
		export_split_key_value(node->cmd->argv[i], &key, &value);
		if (is_valid_key(key))
			printf("error\n");
		else
			add_env(&env_list, key, value);
		free(key);
		free(value);
	}
}
