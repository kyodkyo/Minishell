/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:11:04 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 04:22:16 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute_command(t_ASTNode *node, t_list *env_list);

void	execute_node(t_ASTNode *node, t_list *env_list)
{
	if (node->type == T_CMD)
		execute_command(node, env_list);
	if (node->type == T_REDIR_IN)
		redir_in(node);
	if (node->type == T_REDIR_OUT)
		redir_out(node);
	if (node->type == T_REDIR_HERE)
		redir_heredoc(node);
	if (node->type == T_REDIR_APPEND)
		redir_out_append(node);
	if (node->type == T_REDIR_ERR)
		dup2(STDOUT_FILENO, STDERR_FILENO);
}

void	execute_command(t_ASTNode *node, t_list *env_list)
{
	if (node->left)
		execute_command(node->left, env_list);
	if (node->type == T_CMD)
	{
		if (node->value == NULL)
			return ;
		if (built_in(node, env_list) == 0)
			return ;
		else
			execute_fork(node, env_list);
	}
	else
		execute_node(node, env_list);
}
