/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 17:04:48 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	built_in(t_ASTNode *node, t_list *env_list)
{
	to_lowercase(node->value);
	if (!cmp_str(node->value, "cd"))
		cd(node, env_list);
	else if (!cmp_str(node->value, "echo"))
		echo(node);
	else if (!cmp_str(node->value, "env"))
	{
		if (node->cmd->argv[1])
		{
			perror("env");
			return (0);
		}
		env(env_list);
	}
	else if (!cmp_str(node->value, "exit"))
		built_in_exit(node);
	else if (!cmp_str(node->value, "export"))
		export(node, env_list);
	else if (!cmp_str(node->value, "pwd"))
		pwd();
	else if (!cmp_str(node->value, "unset"))
		unset(node, env_list);
	else
		return (-1);
	return (0);
}
