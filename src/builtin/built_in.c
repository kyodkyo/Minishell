/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 17:17:36 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in(t_ASTNode *node, t_list *env_list, t_io *io)
{
	to_lowercase(node->value);
	if (!cmp_str(node->value, "cd"))
		cd(node, env_list);
	else if (!cmp_str(node->value, "echo"))
		echo(node, io);
	else if (!cmp_str(node->value, "env"))
		env(env_list, io);
	else if (!cmp_str(node->value, "exit"))
		built_in_exit(node);
	else if (!cmp_str(node->value, "export"))
		export(node, env_list, io);
	else if (!cmp_str(node->value, "pwd"))
		pwd(io);
	else if (!cmp_str(node->value, "unset"))
		unset(node, env_list);
	else
		return (-1);
	return (0);
}
