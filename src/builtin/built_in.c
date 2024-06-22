/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 01:29:40 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in(t_ASTNode *node, t_list *env_list, t_io *io)
{
	if (node->value[0])
		return (-1);
	to_lowercase(&node->value[0]);
	if (!cmp_str(&node->value[0], "cd"))
		cd(node, env_list);
	else if (!cmp_str(&node->value[0], "echo"))
		echo(node, io);
	else if (!cmp_str(&node->value[0], "env"))
		env(env_list, io);
	else if (!cmp_str(&node->value[0], "exit"))
		built_in_exit(node);
	else if (!cmp_str(&node->value[0], "export"))
		export(node, env_list, io);
	else if (!cmp_str(&node->value[0], "pwd"))
		pwd(io);
	else if (!cmp_str(&node->value[0], "unset"))
		unset(node, env_list);
	else
		return (-1);
	return (0);
}
