/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 21:48:47 by woonshin         ###   ########.fr       */
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
		env(env_list);
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
